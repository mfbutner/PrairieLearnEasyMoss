import shlex
import subprocess
import json
import sys
from pathlib import Path
from typing import Any
from typing import TypedDict

#-------NOTES-------
# *

# tell @mfbut:
# - zip files still unaccounted for.
# global options: overwritten within assignment (done)
# key is not in json if info is empty
# unzip before going through files, this will create a new file
# -d might require all folders to be flattened (give different names to files w/ same name)
# b/c -d might require all files to be in one folder, use shutil

# put supported languages in a separate file/ config guidelines in a separate file
# typed dict instead of typehinting dicts
# isinstance() instead of != for checking json info
# chain maps: if not in child, looks in parent.
# check if path works: open()

# class Json_Info(TypedDict):
#     starting_path: str
#     num_assignments: int
#     comment: str

def check_json_key(sample_json: dict[str, Any], json_info: dict[str, Any], error_string: str, are_keys_required: bool) -> None:
    """ Checks if information in JSON file is valid to run MOSS command.
    Args:
        json_info (dict [str, Any]): information from JSON file contained in a dict
    """
    for key, value in sample_json.items():
        if are_keys_required:
            if key not in json_info:
                print(f"Error: Required key [{error_string}\"{key}\"] is not in configuration JSON file.")
                exit(0)
        if key in json_info:
            if type(json_info[key]) != type(value):
                print(f'Error: Key ["{key}"] is not of type {type(value)}')
                exit(0)

def json_info_validation(json_info: dict[str, Any]) -> None:
    """ Checks if information in JSON file is valid to run MOSS command.
    Args:
        json_info (dict [str, Any]): information from JSON file contained in a dict
    """

    json_check_dict = {
        "starting_path": "string", 
        "num_assignments": 1, 
        "comment": "string", 
        "number_of_matches_to_show": 1, 
        "language": "string", 
        "assignment_info": [{}]
        }
    
    json_check_dict_assignment = {
        "submitted_files": ["string"],
        "base_files": ["string"]
    }
    supported_languages = ("c", "cc", "java", "ml", "pascal", "ada", "lisp", "scheme", "haskell", "fortran", "ascii", "vhdl", "perl", "matlab", "python", "mips", "prolog", "spice", "vb", "csharp", "modula2", "a8086", "javascript", "plsql", "verilog")
    
    # Checking global keys
    check_json_key(json_check_dict, json_info, "", True)
    if (json_info["language"]).lower() not in supported_languages:
        print(f"Error: Given language \"{json_info['language']}\" is not one of the supported languages.")
        exit(0)

    # Checking keys in each assignment info
    for assignment in json_info["assignment_info"]:
        check_json_key(json_check_dict_assignment, assignment, "\"assignment_info\": ", True)
        check_json_key(json_check_dict, assignment, "\"assignment_info\": ", False)         
        if (assignment["language"]).lower() not in supported_languages:
                print(f"Error: Given language \"{assignment['language']}\" in \"assignment_info\" is not one of the supported languages.")
                exit(0)

def get_moss_command(config_data: dict, assignment_info: dict, homework_file_paths: list, base_file_paths: list) -> list:
    """Creates a moss command as a string from info specified by user.

    Args:
        config_data (dict): dictionary of all configuration info from JSON
        assignment_info (dict): dictionary of info for the assignment for command
        homework_file_paths (list): list of all file paths for this homework assignment
        base_file_paths (list): list of all file paths for base files for this assignment

    Returns:
        list: returns moss command in the form of a list of arguments
    """
    # moss [-l language] [-d] [-b basefile1] ... [-b basefilen] [-m #] [-c "string"] file1 file2 file3 ...
    # list of arguments, " ".join
    try:
        moss_command = config_data["moss_path"]
    except KeyError:
        moss_command = "./moss.sh" #should be path to moss in json, defualt is ./moss.sh or something

    try: #LANGUAGE
        moss_command += f' -l {(assignment_info["language"]).lower()}'
    except:
        moss_command += f' -l {(config_data["language"]).lower()}'

    #BASE FILES
    if base_file_paths != []: # if a list is empty its false?
        for file in base_file_paths:
            moss_command += f' -b {file}'

    #DIRECTORIES      
    moss_command += " -d"

    # if "are_submissions_by_directory" not in assignment_info or  
    # if the option is not there at all, add -d
    # if the option is true, add -d

    
    # try:
    #     if assignment_info["are_submissions_by_directory"]:
    #         moss_command += " -d"
    # except:
    #     if config_data["are_submissions_by_directory"]:
    #         moss_command += " -d"

    try: #MAX APPEARANCES BEFORE IGNORED
        moss_command += f' -m {str(assignment_info["max_appearances_before_ignored"])}'
    except:
        moss_command += f' -m {str(config_data["max_appearances_before_ignored"])}'

    try: #COMMENT
        moss_command += f' -c "{assignment_info["comment"]}"'
    except:
        moss_command += f' -c "{config_data["comment"]}"'
    
    #FILE PATHS
    for file in homework_file_paths:
        moss_command += f' {file}'

    moss_command = shlex.split(moss_command) ## gets string and splits into a list
    return moss_command    

def get_json_info(json_path:str) -> dict:
    """ Gets configuration info from given JSON file and stores info into a nested dictionary.

    Args:
        json_path (_type_): _description_

    Returns:
        _type_: _description_
    """
    json_file = open(json_path)
    config_data = json.load(json_file)
    json_file.close()  
    return config_data

# Gets paths for all specified files from a starting directory path.
def get_file_paths(desired_files:list, starting_path: str) -> list:
    """ Gets configuration info from given JSON file and stores info into a nested dictionary.

    Args:
        desired_files

    Returns:
        _type_: _description_
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
        config_data = get_json_info(sys.argv[1]) # config data is a dict
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
        #Runs the moss command
        #print(moss_command)
        subprocess.run(moss_command) # .run takes a list of arguments, create w/ shlex
        assignment_index += 1

main()