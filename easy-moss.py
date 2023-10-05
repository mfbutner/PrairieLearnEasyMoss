import subprocess
import json
import sys
import os
import tempfile
import inspect
import shutil
import copy
import tarfile
from pathlib import Path
from typing import NotRequired, get_args, get_origin
try:
    from typing import TypedDict
except:
    from typing_extensions import TypedDict

from collections import ChainMap
from zipfile import ZipFile

# -------NOTES-------

# for get all files
# pass in question name and check if question name is in? question_name + **/* + rest < ex

# for putting the question name in front of the files:
# how would the program know which file belonged to which assignment/question? 
# also for filtering out the files of each assignment shouldnt the user specify it in moss.json?
# ex. putting quadratic*.c in moss.json
# rather than filtering through question name like so: question_name + **/* + rest

# tar files?

class Config_Data(TypedDict):
    starting_path: NotRequired[str]
    moss_path: NotRequired[str]
    comment: NotRequired[str]
    number_of_matches_to_show: NotRequired[int]
    max_appearances_before_ignored: NotRequired[int]
    language: NotRequired[str]
    assignment_info: list  # [dict]
    question_name: NotRequired[str]

class Json_Info(TypedDict):
    starting_path: str
    moss_path: NotRequired[str]
    comment: NotRequired[str]
    number_of_matches_to_show: NotRequired[int]
    max_appearances_before_ignored: NotRequired[int]
    question_name: str
    language: str
    submitted_files: list[str]
    base_files: NotRequired[list]  # list[str]?

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

def unzip_files(homework_file_paths: list[str], question_name: str) -> None:
    """Extracts contents of zipfiles into a temporary directory, renames contents of zipfile, flattens contents to parent directory.

    Args:
        homework_file_paths (list[str]): path names of all files inside "starting path" directory
        global_temp_dir_name ([str]): name of the temporary global directory
    """
    # temp folder ex: /var/folders/fx/gtt4zm914w7djxzxg0hgdv140000gn/T/tmpktd1ldnx
    # question_name + path without temporary directory name

    for homework_path in homework_file_paths:
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
            homework_file_paths.remove(homework_path)

        #FOR TAR FILES: DOESN'T WORK
        elif homework_path.endswith("tar.gz"):
            print("hi")
            with tarfile.open(homework_path,'r') as tar_object:
                # Create new folder so we don't clutter the main one (also solves duplicate name issue)
                temp_dir = tempfile.TemporaryDirectory()
                tar_object.extractall(path=temp_dir.name)

                flattened_directory_path = "/".join(homework_path.split("/")[:-1])
                for path, dir_names, file_names in os.walk(temp_dir.name):
                    path_with_underscores = path.replace(temp_dir.name,"").replace(os.path.sep, "_") #<-No temp dir name
                    for file in file_names:
                        shutil.move(os.path.join(path, file),
                                    os.path.join(flattened_directory_path, f"{question_name}_{path_with_underscores}_{file}"))
            os.remove(homework_path) #delete zip file
            homework_file_paths.remove(homework_path)

    # if the folder still has zip files, run function again (ONLY raises warning as of now)
    if has_zip_files(homework_file_paths):
        print("Warning: There are still nested zipfiles in the specified directory.\n")

def is_value_correct(assignment_value, correct_type) -> bool:
    """ Checks if the type of a given key matches the type of a given value. 
        If given a list, checks if items inside list matches the type of value.

    Args:
        assignment_value (Any): given value
        correct_type (_type_): type to check value against, ex. str

    Returns:
        bool: true if key matches, false if key doesn't match
    """
    if get_origin(correct_type) is list: # check items inside of list are of correct type
        correct_type = get_args(correct_type)
        for item_in_list in assignment_value:
            if not isinstance(item_in_list, correct_type):
                return False
    else:
        if not isinstance(assignment_value, correct_type):
            return False
    return True 

def check_json_keys(json_info: Json_Info):
    """Checks if keys given in configuration JSON are of correct type, and that required keys exist in at least one instance in the global or assignment scopes.

    Args:
        json_info (Json_Info): dict of information to be checked
    """
    key_types = inspect.get_annotations(Json_Info)
    supported_languages = (
        "c", "cc", "java", "ml", "pascal", "ada", "lisp", "scheme", "haskell", "fortran", "ascii", "vhdl", "perl",
        "matlab",
        "python", "mips", "prolog", "spice", "vb", "csharp", "modula2", "a8086", "javascript", "plsql", "verilog")
    error_messages = []

    for position, assignment in enumerate(json_info):
        if 'question_name' in assignment:
            question_name = assignment['question_name']
        else:
            question_name = f"Assignment {position + 1}"

        for key, value in key_types.items():
            if get_origin(value) is NotRequired:
                value = (get_args(value))[0]
                if key in assignment:
                    if not is_value_correct(assignment[key], value):
                        wrong_key_err = f'Value of "{key}" is "{assignment[key]}", when it must be of type "{value}" in assignment "{question_name}" or global keys.'
                        error_messages.append(wrong_key_err)  
            else:
                if key not in assignment: # checks if all required keys are in assignment or global scope
                    missing_key_err = f'Required key "{key}" is missing in assignment "{question_name}" or global keys.'
                    error_messages.append(missing_key_err)
                elif not is_value_correct(assignment[key], value): # checks if value is correct
                    wrong_key_err = f'Value of "{key}" is "{assignment[key]}", when it must be of type "{value}" in assignment "{question_name}" or global keys.'
                    error_messages.append(wrong_key_err)
                elif key == "language": # checks if language is one of the supported languages
                    if assignment[key].lower() not in supported_languages:
                        wrong_lang_err = f'Given language "{assignment[key]}" in assignment "{assignment["question_name"]}" is not one of the supported languages.'
                        error_messages.append(wrong_lang_err) 
                elif (key == "moss_path") or (key == "starting_path"): # checks if given paths are valid
                    if not (os.path.isfile(assignment[key]) or os.path.isdir(assignment[key])):
                        invalid_moss_path_err = f'"{assignment[key]}" in assignment "{question_name} is not a valid path.'
                        error_messages.append(invalid_moss_path_err)

    if error_messages:
        print("Your configuration JSON file has these following issues:", file=sys.stderr)
        print("---------------------------------------------------------", file=sys.stderr)
        for position, message in enumerate(error_messages):
            print(f'{position + 1}. {message}', file=sys.stderr)
        exit(1)

def json_info_validation(config_data: Config_Data) -> list[Json_Info]:
    """Checks if configuration data is valid. If valid, returns a list of moss arguments, prioritizing assignment arguments.

    Args:
        config_data (Config_Data): dict of all information in given configuration file

    Returns:
        list[ChainMap]: if information is valid, returns a list of keys to be used in moss command
    """
    global_info = copy.copy(config_data)
    if "assignment_info" in global_info:
        del global_info["assignment_info"]
    global_info = ChainMap(global_info)

    filtered_assignment_info = []
    for assignment in config_data["assignment_info"]:
        filtered_assignment_info.append(global_info.new_child(assignment))
    
    check_json_keys(filtered_assignment_info)

    return filtered_assignment_info

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
        moss_command.append("./moss.sh")  # should be path to moss in json, defualt is ./moss.sh or something

    moss_command.extend(['-l', (assignment["language"]).lower()])
    moss_command.append('-d')
    if "comment" in assignment:
        moss_command.extend(['-c', (assignment["comment"])])
    if "max_appearances_before_ignored" in assignment:
        moss_command.extend(['-m', str(assignment["max_appearances_before_ignored"])])
    moss_command.extend(base_file_paths)
    moss_command.extend(homework_file_paths)

    return moss_command

def get_json_info(json_path: os.PathLike) -> Config_Data:
    """ Gets configuration info from given JSON file and stores info into a nested dictionary.

    Args:
        json_path (os.PathLike): path to JSON file containing configuration info

    Returns:
        Global_Json_Info: nested dictionary with all configuration info from JSON file
    """
    with open(json_path) as json_file:
        config_data = json.load(json_file)
    return config_data

def get_file_paths(desired_files: list[str], starting_path: str) -> list[str]:
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
        p = Path(starting_path).glob('**/*' + assignment_name)
        all_file_paths.extend((f'{x}' for x in p if x.is_file()))

    for path in all_file_paths:
        if "_MACOSX" in path:
            all_file_paths.remove(path)  # TODO: come up with better way to avoid this file?

    return all_file_paths

def run_easy_moss(filtered_assignment_info: Json_Info):
    """ Creates and runs a moss command for each assignment.

    Args:
        config_data (Json_Info): all configuration data from given JSON file
    """

    for assignment in filtered_assignment_info:
        temp_dir = tempfile.TemporaryDirectory()
        global_temp_dir = temp_dir.name
        
        # copies all files from starting path dir to global temp dir
        global_temp_dir = shutil.copytree(assignment["starting_path"], global_temp_dir, dirs_exist_ok=True)

        # unzips and flattens files
        question_name = assignment["question_name"]
        all_paths = get_file_paths(["*"], global_temp_dir)
        print(all_paths)
        unzip_files(all_paths, question_name)

        # TODO: file names need to start with question_name as well
        homework_file_paths = get_file_paths(assignment["submitted_files"],
                                             global_temp_dir)  # strings of paths of all .c
        base_file_paths = get_file_paths(assignment["base_files"], global_temp_dir)
        moss_command = get_moss_command(assignment, homework_file_paths, base_file_paths)
        
        subprocess.run(moss_command)

def main():
    if len(sys.argv) != 2:
        print("Usage: ./easy-moss <path to json config file>")
        exit(0)

    try:
        config_data = get_json_info(sys.argv[1])
    except FileNotFoundError or PermissionError or ValueError or IndexError as err:
        print(f"{err}", file=sys.stderr)
        exit(1)
    except json.decoder.JSONDecodeError as err:
        print(f"Given file is not properly configured as a JSON file.\n{err}", file=sys.stderr)
        exit(1)

    filtered_assignment_info = json_info_validation(config_data)

    run_easy_moss(filtered_assignment_info)

main()