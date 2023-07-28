import shlex
import subprocess
import json
import sys
import os
import inspect
from pathlib import Path
from typing import TypedDict
from typing_extensions import NotRequired # didn't work b4 running pip3 install typing-extensions
from collections import ChainMap
import copy
from zipfile import ZipFile

#-------NOTES-------
# type checking gets complicated with the NotRequired class: find workaround
# new type: fixed set of values (enum?)
    
class Config_Data(TypedDict):
    starting_path: NotRequired[str]
    moss_path: NotRequired[str]
    comment: NotRequired[str]
    number_of_matches_to_show: NotRequired[int]
    max_appearances_before_ignored: NotRequired[int]
    language: NotRequired[str]
    assignment_info: list

class Json_Info(TypedDict):
    starting_path: str
    moss_path: NotRequired[str]
    comment: NotRequired[str]
    number_of_matches_to_show: NotRequired[int]
    max_appearances_before_ignored: NotRequired[int]
    question_name: str
    language: str
    submitted_files: list
    base_files: NotRequired[list]


def unzip_files(homework_file_paths: list) -> None:
    for homework_path in homework_file_paths:
            if homework_path[-4:] == ".zip":
                with ZipFile(homework_path) as zip_object:
                    # Create new folder so we don't clutter the main one (also solves duplicate name issue)
                    os.mkdir(homework_path[:-4])
                    zip_object.extractall(path=homework_path[:-4])


def check_json_keys(json_info: Json_Info):
    key_types = inspect.get_annotations(Json_Info)
    supported_languages = ("c", "cc", "java", "ml", "pascal", "ada", "lisp", "scheme", "haskell", "fortran", "ascii", "vhdl", "perl", "matlab", "python", "mips", "prolog", "spice", "vb", "csharp", "modula2", "a8086", "javascript", "plsql", "verilog")

    for key, value in key_types.items():
        for assignment in json_info:
            if "NotRequired" in str(value):
                if ((str(type(assignment[key])))[8:-2] != (str(value))[30:-1]):
                    print(f'Error: The value of "{key}" must be of type {value}.')
                    exit(1)
            else:
                if key not in assignment: 
                    print(f'Error: Required key "{key}" is not in configuration JSON.')
                    exit(1)
                if (type(assignment[key]) != value):
                    print(f'Error: The value of "{key}" must be of type {value}.')
                    exit(1)
            if ("language" in assignment) and (assignment["language"]).lower() not in supported_languages:
                print(f'Error: Given language "{assignment["language"]}" in assignment "{assignment["question_name"]}" is not one of the supported languages.')
                exit(1)


def json_info_validation(config_data: Config_Data) -> list[ChainMap]:
    global_info = copy.copy(config_data)
    del global_info["assignment_info"]
    global_info = ChainMap(global_info)
    
    filtered_assignment_info = []

    for assignment in config_data["assignment_info"]:
        filtered_assignment_info.append(global_info.new_child(assignment))
    check_json_keys(filtered_assignment_info)

    return filtered_assignment_info

def get_moss_command(assignment, homework_file_paths: list, base_file_paths: list) -> list:
    """Creates a moss command as a string from info specified by user.

    Args:
        config_data (Global_Json_Info): dictionary of all configuration info from JSON
        assignment_info (Assignment_Json_Info): dictionary of info for the assignment for command
        homework_file_paths (list): list of all file paths for this homework assignment
        base_file_paths (list): list of all file paths for base files for this assignment

    Returns:
        list: returns moss command in the form of a list of arguments
    """
    # moss [-l language] [-d] [-b basefile1] ... [-b basefilen] [-m #] [-c "string"] file1 file2 file3 ...
    moss_command = []

    try:
        moss_command.append(assignment["moss_path"])
    except KeyError:
        moss_command.append("./moss.sh") #should be path to moss in json, defualt is ./moss.sh or something
    
    moss_command.extend(['-l', (assignment["language"]).lower()])
    moss_command.append('-d')
    if assignment["comment"]:
        moss_command.extend(['-c', (assignment["comment"])])
    if assignment["max_appearances_before_ignored"]:
        moss_command.extend(['-m', str(assignment["max_appearances_before_ignored"])])
    moss_command.extend(base_file_paths)
    moss_command.extend(homework_file_paths)

    return moss_command    

def get_json_info(json_path: str) -> Config_Data:
    """ Gets configuration info from given JSON file and stores info into a nested dictionary.

    Args:
        json_path (str): path to JSON file containing confiuration info

    Returns:
        Global_Json_Info: nested dictionary with all configuration info from JSON file
    """
    json_file = open(json_path)
    config_data = json.load(json_file)
    json_file.close()  
    return config_data


def get_file_paths(desired_files: list, starting_path: str) -> list:
    """ Gets paths for all specified files from a starting directory path.

    Args:
        desired_files (list): list of patterns of homework files to be checked
        starting_path (str): path to folder containing homework files

    Returns:
        list: of all paths to each desired homework file
    """
    all_file_paths = []

    p = Path(starting_path).glob('**/*')

    for assignment_name in desired_files:
        if assignment_name.startswith('*'):
            assignment_name = assignment_name.lstrip('*')
        p = Path(starting_path).glob('**/*' + assignment_name)
        file = [x for x in p if x.is_file()]

        for file_path in file:
            all_file_paths.append(str(file_path))

    return all_file_paths


def run_easy_moss(filtered_assignment_info):
    """ Creates and runs a moss command for each assignment.

    Args:
        config_data (Json_Info): all configuration data from given JSON file
    """
    for assignment in filtered_assignment_info:
        homework_file_paths = get_file_paths(assignment["submitted_files"], assignment["starting_path"]) #strings of paths of all .c
        base_file_paths = get_file_paths(assignment["base_files"], assignment["starting_path"])
        moss_command = get_moss_command(assignment, homework_file_paths, base_file_paths)
        # print(moss_command)
        subprocess.run(moss_command) # .run takes a list of arguments, create w/ shlex


def main():
    if len(sys.argv) != 2:
        print("Usage: ./easy-moss <path to json config file>")
        exit(0) 
        
    try:
        config_data = get_json_info(sys.argv[1])
    except json.decoder.JSONDecodeError as err: ## fix: specific errors (ValueError, IndexError)
        print(f"Error: Given file is not properly configured as a JSON file.\n{err}")
        exit(0)

    #UNZIP FILES
    #DOESNT check for individual assignment json
    all_paths = get_file_paths(["*"], config_data["starting_path"])
    unzip_files(all_paths)

    filtered_assignment_info = json_info_validation(config_data)

    run_easy_moss(filtered_assignment_info)

main()