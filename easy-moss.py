import subprocess
import json
import sys
import os
import tempfile
import inspect
import shutil
import copy
import zipfile
from pathlib import Path

from typing import Any, NotRequired, get_args, get_origin

try:
    from typing import TypedDict
except:
    from typing_extensions import TypedDict

from collections import ChainMap
from zipfile import ZipFile


# -------NOTES-------

# if moss path exists, check that it is valid

# print to stdout, 2> to text.txt

# zip file issues
# - homework_path has a different value depending on location in unzip function
# - unzipped .c files are being placed in Homework3 instead of global temp
# - there are 2 of them
# - they aren't .c files?


# type checking gets complicated with the NotRequired class: find workaround
# new type: fixed set of values (enum?)
# specify what the lists are of ex. list[int]
# update python

# run moss command with new global temp?

# for get all files
# pass in question name and check if question name is in? question_name + **/* + rest < ex
# old name: homework name, file name
# new name: add question name, python path to file within zip
# people might not put zip files inside of zip files

class Config_Data(TypedDict):
    starting_path: NotRequired[str]
    moss_path: NotRequired[str]
    comment: NotRequired[str]
    number_of_matches_to_show: NotRequired[int]
    max_appearances_before_ignored: NotRequired[int]
    language: NotRequired[str]
    assignment_info: list  # [dict]


class Json_Info(TypedDict):  # fix: change name to assignment_info
    starting_path: str
    moss_path: NotRequired[str]
    comment: NotRequired[str]
    number_of_matches_to_show: NotRequired[int]
    max_appearances_before_ignored: NotRequired[int]
    question_name: str
    language: str
    submitted_files: list[str]
    base_files: NotRequired[list]  # list[str]?

# def unique_file_name(file_name, directory) -> str:
#     if 

def has_zip_files(file_names) -> bool:
    """Checks if a given list of files includes .zip files.

    Args:
        file_names (_type_): names of files to check

    Returns:
        bool: has zip files or doesn't have zip files
    """
    for filename in file_names:
        if filename.endswith('.zip'):
            return True
    return False


def unzip_files(homework_file_paths: list[str], global_temp_dir_name: str) -> None:
    """Extracts contents of zipfiles into a temporary directory, renames contents of zipfile, flattens contents to parent directory.

    Args:
        homework_file_paths (list[str]): path names of all files inside "starting path" directory
        global_temp_dir_name ([str]): name of the temporary global directory
    """
    # temp folder ex: /var/folders/fx/gtt4zm914w7djxzxg0hgdv140000gn/T/tmpktd1ldnx
    # shutil.copy(file_name1, file_name1 + "/..") incompatible with tempdir
    # Directory not empty error when trying to delete the temp directory
    # not initially checking if the zipfile happens to have the same name as another folder in the parent directory

    for homework_path in homework_file_paths:
        # print("HERE!!!!!!! ", homework_file_paths)
        if homework_path.endswith(".zip"):
            with ZipFile(homework_path) as zip_object:
                # Create new folder so we don't clutter the main one (also solves duplicate name issue)
                #temp_dir = homework_path[:-4]
                #os.mkdir(temp_dir)
                temp_dir = tempfile.TemporaryDirectory()
                
                #shutil.move(temp_dir.name, global_temp_dir_name)
                zip_object.extractall(path=temp_dir.name)
                
                # print(os.listdir(temp_dir.name), file = sys.stderr)
                for path, dir_names, file_names in os.walk(temp_dir.name):
                    path_with_underscores = path.replace(os.path.sep,"_")
                    for file in file_names:
                        #shutil.move(os.path.join(path, file), os.path.join(temp_dir.name, f'{path_with_underscores}_{file}'))
                        #new_file_name = f'{path_with_underscores}_{file}'
                        #os.rename(file, new_file_name)
                        flattened_directory_path = "/".join(homework_path.split("/")[:-1])
                        print(flattened_directory_path, file = sys.stderr)
                        shutil.move(os.path.join(path, file), os.path.join(flattened_directory_path, f"{path_with_underscores}_{file}"))
                        # for path with underscores:
                        # 

                # files_in_zip = get_file_paths(["*"], temp_dir.name)
                # files_in_parent_folder = get_file_paths(["*"], temp_dir.name + "/..")
                # #Renaming files
                # for file_name1 in files_in_zip:
                #     for file_name2 in files_in_parent_folder:
                #         if file_name1 == file_name2:
                #             basename = os.path.basename(file_name1)
                #             os.rename(file_name1, file_name1[:-len(basename)] + file_name1.replace("/","_") + file_name1[-len(basename):])
                # #Flattening zip
                # for file_name1 in files_in_zip:
                #     shutil.move(file_name1, temp_dir.name + "/..")
                # os.remove(homework_path) #delete zip file

    # if the folder still has zip files, run function again (ONLY raises warning as of now)
    if has_zip_files(homework_file_paths):
        print("Warning: There are still nested zipfiles in the specified directory.\n")
    #     unzip_files(homework_file_paths)

def check_key_types(assignment_key, key_type) -> bool:
    """ Checks if the type of a given key matches the type of a given value. 
        If given a list, checks if items inside list matches the type of value.

    Args:
        value (Any): given key
        expected_type (_type_): type to check key against, ex. str

    Returns:
        bool: true if key matches, false if key doesn't match
    """

    # print(value)

    if get_origin(expected_type) is list:  # check items inside of list are of correct type
        expected_type = get_args(expected_type)

        def is_key_type(item_in_list):
            isinstance(item_in_list, expected_type)

        return isinstance(value, list) and all(map(is_key_type, value))
    else:
        return isinstance(value, expected_type)


def check_json_keys(json_info: Json_Info):
    """Checks if keys given in configuration JSON are of correct type, and that required keys exist in at least one instance in the global or assignment scopes.

    Args:
        json_info (Json_Info): dict of information to be checked
    """
    key_types = inspect.get_annotations(Json_Info)
    supported_languages = ("c", "cc", "java", "ml", "pascal", "ada", "lisp", "scheme", "haskell", "fortran", "ascii", "vhdl", "perl", "matlab", "python", "mips", "prolog", "spice", "vb", "csharp", "modula2", "a8086", "javascript", "plsql", "verilog")
    missing_required_keys = []
    incorrect_type_keys = []

    for assignment in json_info:
        for key, key_type in key_types.items(): #rename value
            if get_origin(key_type) is not NotRequired: 
                if key not in assignment: 
                    missing_required_keys.append(key)
                elif not check_key_types(assignment[key], key_type):
                    incorrect_type_keys.append(key)
            else:  # key is not required
                key_type = (get_args(key_type))[0]
                if key in assignment:
                    if not is_type(assignment[key], key_type):
                        incorrect_type_keys.append(key)
                        
        if ("language" in assignment) and isinstance(assignment["language"], str) and (assignment["language"]).lower() not in supported_languages:
            print(f'Error: Given language "{assignment["language"]}" in assignment "{assignment["question_name"]}" is not one of the supported languages.')
            exit(1)
        if ("moss_path" in assignment) and isinstance(assignment["language"], str):
            if not os.path.isfile(assignment["moss_path"]):
                print(f'Error: "{assignment["moss_path"]}" is not a valid directory')
                exit(1)
        if not (os.path.isdir(assignment["starting_path"])):  # fix
            print(f'Error: "{assignment["starting_path"]}" is not a valid directory.')
            exit(1)

    if len(missing_required_keys) != 0:
        for missing_key in missing_required_keys:
            print(f'Error: Required key "{missing_key}" is not in configuration JSON.')
        exit(1)

    if incorrect_type_keys:
        for incorrect_key in incorrect_type_keys:
            type_val = key_types[incorrect_key]
            print(f'Error: The value of "{incorrect_key}" must be of type "{type_val}".')
        exit(1)


def json_info_validation(config_data: Config_Data) -> list[Json_Info]:  ## fix: specify what chainmap
    """Checks if configuration data is valid. If valid, returns a list of moss arguments, prioritizing assignment arguments.

    Args:
        config_data (Config_Data): dict of all information in given configuration file

    Returns:
        list[ChainMap]: if information is valid, returns a list of keys to be used in moss command
    """
    global_info = copy.copy(config_data)
    del global_info["assignment_info"]  # TODO: Check for key error as assignment_info may be missing if bad json given
    global_info = ChainMap(global_info)

    filtered_assignment_info = []

    for assignment in config_data["assignment_info"]:
        filtered_assignment_info.append(global_info.new_child(assignment))
    check_json_keys(filtered_assignment_info)

    return filtered_assignment_info


# TODO add type hints for assignment
def get_moss_command(assignment, homework_file_paths: list[str], base_file_paths: list[str]) -> list[str]:
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


def get_json_info(json_path: str) -> Config_Data:  # TODO: str -> os.Pathlike
    """ Gets configuration info from given JSON file and stores info into a nested dictionary.

    Args:
        json_path (str): path to JSON file containing configuration info

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

    return all_file_paths


def run_easy_moss(filtered_assignment_info):  # TODO: Add type hints
    """ Creates and runs a moss command for each assignment.

    Args:
        config_data (Json_Info): all configuration data from given JSON file
    """

    for assignment in filtered_assignment_info:
        # temp_dir = tempfile.TemporaryDirectory() #fix
        # global_temp_dir = temp_dir.name
        global_temp_dir = "./global" # TODO: make work for real and not just testing
        # copies all files from starting path dir to global temp dir
        global_temp_dir = shutil.copytree(assignment["starting_path"], global_temp_dir, dirs_exist_ok=True)

        # unzips and flattens files
        all_paths = get_file_paths(["*"], global_temp_dir)
        # copies all files from starting path dir to global temp dir
        # for path in all_paths:
        #     shutil.copy(path, global_temp_dir)
        unzip_files(all_paths, global_temp_dir)

        # TODO: file names need to start with question_name as well
        homework_file_paths = get_file_paths(assignment["submitted_files"],
                                             global_temp_dir)  # strings of paths of all .c
        base_file_paths = get_file_paths(assignment["base_files"], global_temp_dir)
        moss_command = get_moss_command(assignment, homework_file_paths, base_file_paths)
        print(moss_command)
        #subprocess.run(moss_command) # .run takes a list of arguments
        #shutil.rmtree(global_temp_dir) # doesn't delete global directory until moss command finishes
        # # removes temporary directory


def main():
    if len(sys.argv) != 2:
        print("Usage: ./easy-moss <path to json config file>")
        exit(0)

    try:
        config_data = get_json_info(sys.argv[1])
    except json.decoder.JSONDecodeError as err:  ## fix: specific errors (ValueError, IndexError)
        print(f"Error: Given file is not properly configured as a JSON file.\n{err}")
        exit(0)  # TODO: Non zero exit code when program fails to complete
    # TODO: check for file errors like file not found or permission errors.
    filtered_assignment_info = json_info_validation(config_data)

    run_easy_moss(filtered_assignment_info)

    # try:
    #     run_easy_moss(filtered_assignment_info)
    # finally:
    #     shutil.rmtree("./global")


main()
