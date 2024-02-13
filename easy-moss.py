import subprocess
import json
import sys
import os
import tempfile
import inspect
import shutil
import copy
import tarfile
import json
from pathlib import Path
from typing import NotRequired, get_args, get_origin
try:
    from typing import TypedDict
except:
    from typing_extensions import TypedDict

from collections import ChainMap
from zipfile import ZipFile
from jsonschema import validate, RefResolver

class Config_Data(TypedDict):
    starting_path: NotRequired[str]
    moss_path: NotRequired[str]
    comment: NotRequired[str]
    number_of_matches_to_show: NotRequired[int]
    max_appearances_before_ignored: NotRequired[int]
    language: NotRequired[str]
    assignment_info: list#[dict]

class Json_Info(TypedDict):
    starting_path: str
    moss_path: NotRequired[str]
    comment: NotRequired[str]
    number_of_matches_to_show: NotRequired[int]
    max_appearances_before_ignored: NotRequired[int]
    question_name: str
    language: str
    submitted_files: list#[str] ex. this would show up as a str, not a list
    base_files: NotRequired[list]

def has_zip_files(file_names) -> bool:
    """Checks if a given list of files includes .zip files.

    Args:
        file_names (_type_): names of files to check

    Returns:
        bool: has zip files or doesn't have zip files
    """
    for filename in file_names:
        if filename.endswith(".zip"):
            return True
    return False


def unzip_files(file_paths: list[str], question_name: str) -> None:
    """Extracts contents of zipfiles into a temporary directory, renames contents of zipfile, flattens contents to parent directory.

    Args:
        homework_file_paths (list[str]): path names of all files inside "starting path" directory
        global_temp_dir_name ([str]): name of the temporary global directory
    """
    # temp folder ex: /var/folders/fx/gtt4zm914w7djxzxg0hgdv140000gn/T/tmpktd1ldnx
    # question_name + path without temporary directory name

    #zip files
    for homework_path in file_paths:
        #print(homework_path)
        if homework_path.endswith(".zip"):
            with ZipFile(homework_path) as zip_object:
                # Create new folder so we don't clutter the main one (also solves duplicate name issue)
                temp_dir = tempfile.TemporaryDirectory()
                zip_object.extractall(path=temp_dir.name)

                flattened_directory_path = "/".join(homework_path.split("/")[:-1])
                for path, dir_names, file_names in os.walk(temp_dir.name):
                    path_with_underscores = path.replace(temp_dir.name,"").replace(os.path.sep, "_") #<-No temp dir name
                    for file in file_names:
                        shutil.move(os.path.join(path, file),
                                    os.path.join(flattened_directory_path, f"{question_name}_{path_with_underscores}_{file}"))
            os.remove(homework_path) #delete zip file
            file_paths.remove(homework_path)

        #tar files
        elif homework_path.endswith(".tar.gz"):
            with tarfile.open(homework_path,'r:gz') as tar_object:
                # Create new folder so we don't clutter the main one (also solves duplicate name issue)
                temp_dir = tempfile.TemporaryDirectory()
                tar_object.extractall(path=temp_dir.name)

                flattened_directory_path = "/".join(homework_path.split("/")[:-1])
                for path, dir_names, file_names in os.walk(temp_dir.name):
                    path_with_underscores = path.replace(temp_dir.name,"").replace(os.path.sep, "_") #<-No temp dir name
                    for file in file_names: # move and rename
                        print(f"\nTAR FILE EXTRACTED:\n{question_name}_{path_with_underscores}_{file}\n")
                        shutil.move(os.path.join(path, file),
                                    os.path.join(flattened_directory_path, f"{question_name}_{path_with_underscores}_{file}"))
            os.remove(homework_path) #delete tar file
            file_paths.remove(homework_path)
        elif homework_path.endswith(".tar"):
            with tarfile.open(homework_path,'r') as tar_object:
                # Create new folder so we don't clutter the main one (also solves duplicate name issue)
                temp_dir = tempfile.TemporaryDirectory()
                tar_object.extractall(path=temp_dir.name)

                flattened_directory_path = "/".join(homework_path.split("/")[:-1])
                for path, dir_names, file_names in os.walk(temp_dir.name):
                    path_with_underscores = path.replace(temp_dir.name,"").replace(os.path.sep, "_") #<-No temp dir name
                    for file in file_names: # move and rename
                        print(f"\nTAR FILE EXTRACTED:\n{question_name}_{path_with_underscores}_{file}\n")
                        shutil.move(os.path.join(path, file),
                                    os.path.join(flattened_directory_path, f"{question_name}_{path_with_underscores}_{file}"))
            os.remove(homework_path) #delete tar file
            file_paths.remove(homework_path)

    # if the folder still has zip files, run function again (ONLY raises warning as of now)
    if has_zip_files(file_paths):
        print("Warning: There are still nested files in the specified directory.\n")


def get_moss_command(assignment: Json_Info, homework_file_paths: list[str], base_file_paths: list[str]) -> list[str]:
    """Creates a moss command as a string from info specified by user.

    Args:
        config_data (Global_Json_Info): dictionary of all configuration info from JSON
        assignment_info (Assignment_Json_Info): dictionary of info for the assignment for command
        homework_file_paths (list[str]): list of all file paths for this homework assignment
        base_file_paths (list[str]): list of all file paths for base files for this assignment

    Returns:
        list[str]: returns moss command in the form of a list of arguments
    """
    # moss [-l language] [-d] [-b basefile1] ... [-b basefilen] [-m #] [-c "string"] file1 file2 file3 ...
    moss_command = []

    try:
        moss_command.append(assignment["moss_path"])
    except KeyError:
        moss_command.append("./moss.sh")  # should be path to moss in json, defualt is ./moss.sh

    moss_command.extend(['-l', (assignment["language"]).lower()])
    moss_command.append('-d')
    if "comment" in assignment:
        moss_command.extend(['-c', (assignment["comment"])])
    if "max_appearances_before_ignored" in assignment:
        moss_command.extend(['-m', str(assignment["max_appearances_before_ignored"])])
    moss_command.extend(base_file_paths)
    moss_command.extend(homework_file_paths)

    return moss_command


def json_info_validation(config_data: Config_Data) -> list[Json_Info]:
    """Checks if configuration data is valid. If valid, returns a list of moss arguments, prioritizing assignment arguments.

    Args:
        config_data (Config_Data): dict of all information in given configuration file

    Returns:
        list[ChainMap]: if information is valid, returns a list of keys to be used in moss command
    """
    with open("schema-global.json", "r") as global_schema_file:
        global_schema = json.load(global_schema_file)
    with open("schema-question.json", "r") as question_schema_file:
        question_schema = json.load(question_schema_file)

    # resolve somehow
    resolver = RefResolver.from_schema(question_schema)
    _schema = resolver.resolve(global_schema)

    # validate config data (moss.json)
    try:
        validate(instance=config_data, schema=global_schema)
        print("Validation successful. JSON data conforms to the schema.")
    except Exception as e:
        print("JSON data does not conform to the schema, please fix the following errors:", e)
        exit(0)
    
    global_info = copy.copy(config_data)
    if "assignment_info" in global_info:
        del global_info["assignment_info"] # only have global settings in global_info
    global_info = ChainMap(global_info)

    filtered_assignment_info = []
    for assignment in config_data["assignment_info"]: 
        filtered_assignment_info.append(global_info.new_child(assignment))

    print(filtered_assignment_info)

    return filtered_assignment_info


def json_to_dict(json_path: os.PathLike) -> Config_Data:
    """ Gets configuration info from given JSON file and stores info into a nested dictionary.

    Args:
        json_path (os.PathLike): path to JSON file containing configuration info

    Returns:
        Global_Json_Info: nested dictionary with all configuration info from JSON file
    """
    with open(json_path) as json_file:
        config_data = json.load(json_file)
    return config_data


def get_file_paths(desired_files: list[str], starting_path: str, question_name: str) -> list[str]:
    """ Gets paths for all specified files from a starting directory path.

    Args:
        desired_files (list[str]): list of patterns of homework files to be checked
        starting_path (str): path to folder containing homework files

    Returns:
        list[str]: of all paths to each desired homework file
    """
    all_file_paths = []

    for assignment_name in desired_files:
        assignment_name = assignment_name.lstrip('*')
        if question_name == "":
            p = Path(starting_path).glob('**/*' + assignment_name)
        else:
            p = Path(starting_path).rglob('*' + question_name + '*' + assignment_name)
        all_file_paths.extend((f'{x}' for x in p if x.is_file()))

    for path in all_file_paths:
        if "_MACOSX" in path:
            all_file_paths.remove(path)  # TODO: come up with better way to avoid this file?

    return all_file_paths

def run_easy_moss(filtered_assignment_info: Json_Info) -> str:
    """ Creates and runs a moss command for each assignment.

    Args:
        config_data (Json_Info): all configuration data from given JSON file
    """

    for assignment in filtered_assignment_info:
        # TODO: take tempdir portion out of for loop
        # TODO: check if there are zip files before creating tempdir?
        # TODO: assume that file is a zip file, unzip file and put everything in a tempdir
        temp_dir = tempfile.TemporaryDirectory()
        global_temp_dir = temp_dir.name
        
        # copies all files from starting path dir to global temp dir
        global_temp_dir = shutil.copytree(assignment["starting_path"], global_temp_dir, dirs_exist_ok=True)

        # unzips and flattens files
        question_name = assignment["question_name"]
        zip_paths = get_file_paths([".zip"], global_temp_dir, "")
        tar_paths = get_file_paths([".tar.gz"], global_temp_dir, "")
        unzip_files(zip_paths + tar_paths, question_name)

        homework_file_paths = get_file_paths(assignment["submitted_files"],
                                             global_temp_dir, question_name)  # strings of paths of all .c
        base_file_paths = get_file_paths(assignment["base_files"], global_temp_dir, question_name)
        moss_command = get_moss_command(assignment, homework_file_paths, base_file_paths)
        

        return(moss_command)

def main():
    if len(sys.argv) != 3:
        print("Usage: ./easy-moss <path to json config file> <test1 or test2 if testing>")
        exit(0)

    try:
        config_data = json_to_dict(sys.argv[1])
    except FileNotFoundError or PermissionError or ValueError or IndexError as err:
        print(f"{err}", file=sys.stderr)
        exit(1)
    except json.decoder.JSONDecodeError as err:
        print(f"Given file is not properly configured as a JSON file.\n{err}", file=sys.stderr)
        exit(1)

    filtered_assignment_info = json_info_validation(config_data)
    moss_command = run_easy_moss(filtered_assignment_info)

    if sys.argv[2] == "test1":
        print(moss_command)
    elif sys.argv[2] == "test2":
        print("OMG HII :)")
    else:
        subprocess.run(moss_command)

main()