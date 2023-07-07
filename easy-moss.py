import shlex
import subprocess
import json
import sys
import os
from pathlib import Path
from typing import TypedDict
from typing_extensions import NotRequired # didn't work b4 running pip2 install typing-extensions

#-------NOTES-------
# key is not in json if info is empty 
# put supported languages in a separate file/ config guidelines in a separate file (?)
# chain maps: if not in child, looks in parent.
    
class Json_Info(TypedDict):
    num_assignments: NotRequired[int] # this is considered required, is not required here so I could make the assignment info (is this necessary)
    comment: NotRequired[str]
    number_of_matches_to_show: NotRequired[int]
    language: NotRequired[str]
    max_appearances_before_ignored: NotRequired[int]
    are_submissions_by_directory: NotRequired[int]

class Assignment_Json_Info(Json_Info):
    submitted_files: list[str]
    base_files: list[str]
    
class Global_Json_Info(Json_Info):
    starting_path: str
    assignment_info: list[Assignment_Json_Info]

def check_json_key(sample_json: Json_Info, json_info: Json_Info, error_string: str, are_keys_required: bool) -> None:
    """ Takes in a dict of JSON information with correct keys and a dict of JSON information to be checked.
        Prints error message and exits if required key is not in 

    Args:
        sample_json (Json_Info): JSON info with correct keys
        json_info (Json_Info): JSON info to be checked
        error_string (str): additional information to be printed in error string (ex. error is in assignment_info)
        are_keys_required (bool): skips checking for existence of keys if keys are not required
    """
    supported_languages = ("c", "cc", "java", "ml", "pascal", "ada", "lisp", "scheme", "haskell", "fortran", "ascii", "vhdl", "perl", "matlab", "python", "mips", "prolog", "spice", "vb", "csharp", "modula2", "a8086", "javascript", "plsql", "verilog")

    for key, value in sample_json.items():
        if are_keys_required:
            if key not in json_info:
                print(f'Error: Required key {error_string}["{key}"] is not in configuration JSON file.')
                exit(0)
        if key in json_info:
            if not isinstance((json_info[key]), type(value)):
                print(f'Error: Key {error_string}["{key}"] is not of type {type(value)}')
                exit(0)

    if (json_info["language"]).lower() not in supported_languages:
        print(f'Error: Given language {error_string}"{json_info["language"]}" is not one of the supported languages.')
        exit(0)


def json_info_validation(json_info: Global_Json_Info) -> None:
    """ Checks if information in JSON file is valid to run MOSS command. Exits if info is invalid.
    Args:
        json_info (Global_Json_Info): information from JSON file contained in a dict
    """
    json_check_dict: Global_Json_Info = {
        "starting_path": "string", 
        "num_assignments": 1, 
        "comment": "string", 
        "number_of_matches_to_show": 1, 
        "language": "string", 
        "max_appearances_before_ignored": 1,
        "assignment_info": [{}]
        }
    
    json_check_dict_assignment: Assignment_Json_Info = {
        "submitted_files": ["string"],
        "base_files": ["string"]
    }

    # Checking global keys
    check_json_key(json_check_dict, json_info, "", True)
    if (not os.path.isfile(json_info['starting_path'])) and (not os.path.isdir(json_info['starting_path'])):
        print('Error: Path provided for ["starting_path"] is not a valid file or directory.')
        exit(0)

    # Checking keys in each assignment info
    for assignment in json_info["assignment_info"]:
        check_json_key(json_check_dict_assignment, assignment, "\"assignment_info\": ", True)
        check_json_key(json_check_dict, assignment, "\"assignment_info\": ", False)         


def get_moss_command(config_data: Global_Json_Info, assignment_info: Assignment_Json_Info, homework_file_paths: list, base_file_paths: list) -> list:
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
    try:
        moss_command = config_data["moss_path"]
    except KeyError:
        moss_command = "./moss.sh" #should be path to moss in json, defualt is ./moss.sh or something
    #LANGUAGE
    try: 
        moss_command += f' -l {(assignment_info["language"]).lower()}'
    except KeyError:
        moss_command += f' -l {(config_data["language"]).lower()}'
    #BASE FILES
    if base_file_paths != []: # if a list is empty its false?
        for file in base_file_paths:
            moss_command += f' -b {file}'
    #DIRECTORIES   
    moss_command += " -d"
    # try:
    #     if assignment_info["are_submissions_by_directory"]:
    #         moss_command += " -d"
    # except:
    #     if config_data["are_submissions_by_directory"]:
    #         moss_command += " -d"

    #MAX APPEARANCES BEFORE IGNORED
    try:
        moss_command += f' -m {str(assignment_info["max_appearances_before_ignored"])}'
    except KeyError:
        moss_command += f' -m {str(config_data["max_appearances_before_ignored"])}'
    # COMMENT
    try:
        moss_command += f' -c "{assignment_info["comment"]}"'
    except KeyError:
        moss_command += f' -c "{config_data["comment"]}"'
    #FILE PATHS
    for file in homework_file_paths:
        moss_command += f' {file}'

    moss_command = shlex.split(moss_command) ## gets string and splits into a list
    return moss_command    


def get_json_info(json_path: str) -> Global_Json_Info:
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


def main():
    if len(sys.argv) != 2:
        print("Usage: ./easy-moss <path to json config file>")
        exit(0) 
        
    #Stores Json information
    try:
        config_data = get_json_info(sys.argv[1])
    except:
        print(f"Error: Given file is not properly configured as a JSON file.")
        exit(0)
    json_info_validation(config_data)

    #Creates and runs a moss command for each desired file
    assignment_index = 0
    for assignment_info in config_data["assignment_info"]:
        homework_file_paths = get_file_paths(assignment_info["submitted_files"], config_data["starting_path"]) #strings of paths of all .c
        base_file_paths = get_file_paths(assignment_info["base_files"], config_data["starting_path"])
        
        moss_command = get_moss_command(config_data, assignment_info, homework_file_paths, base_file_paths)
        #print(moss_command)
        subprocess.run(moss_command) # .run takes a list of arguments, create w/ shlex
        assignment_index += 1

main()