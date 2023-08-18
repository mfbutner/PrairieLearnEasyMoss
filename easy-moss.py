import subprocess
import json
import sys
import os
import tempfile
import inspect
import shutil
import copy
from pathlib import Path
try:
    from typing import TypedDict
except:
    from typing_extensions import TypedDict
from typing_extensions import NotRequired # didn't work b4 running pip3 install typing-extensions
from collections import ChainMap
from zipfile import ZipFile

#-------NOTES-------
# type checking gets complicated with the NotRequired class: find workaround
# new type: fixed set of values (enum?)
# specify what the lists are of ex. list[int]

# for get all files
# pass in question name and check if question name is in? question_name + **/* + rest < ex

# issue: being specific with type hints for lists interferes with type checking   
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
    base_files: NotRequired[list]#[str]]

# def create_unique_name(file_name, parent_dir) -> str:
#     counter = 1
#     while file_name in parent_dir:
#         file_name += counter
#         counter += 1
#     return file_name

def has_zip_files(directory):
    for filename in directory:
        if filename.endswith('.zip'):
            return True
    return False


def unzip_files(homework_file_paths: list[str]) -> None:
    """To be completed

    Args:
        homework_file_paths (list[str]): _description_
    """
    # temp folder ex: /var/folders/fx/gtt4zm914w7djxzxg0hgdv140000gn/T/tmpktd1ldnx
    # shutil.copy(file_name1, file_name1 + "/..") incompatible with tempdir
    # Directory not empty error when trying to delete the temp directory
    # not initially checking if the zipfile happens to have the same name as another folder in the parent directory

    for homework_path in homework_file_paths:
        if homework_path.endswith(".zip"):
            with ZipFile(homework_path) as zip_object:
                # Create new folder so we don't clutter the main one (also solves duplicate name issue)
                #temp_dir = homework_path[:-4]
                #os.mkdir(temp_dir)
                temp_dir = tempfile.mkdtemp()
                zip_object.extractall(path=temp_dir) #Is this a path?
                files_in_zip = get_file_paths(["*"], temp_dir)
                #Renaming files
                for file_name1 in files_in_zip:
                    basename = os.path.basename(file_name1)
                    os.rename(file_name1, file_name1[:-len(basename)] + file_name1.replace("/","_") + file_name1[-len(basename):])
                #Flattening zip
                for file_name1 in files_in_zip:
                    shutil.move(file_name1, temp_dir + "/..")
                os.remove(homework_path) #delete zip file
                #shutil.rmtree(temp_dir) #delete temp file

    # if the folder still has zip files, run function again (ONLY raises warning as of now)
    if has_zip_files(homework_file_paths):
        print("Warning: There are still nested zipfiles in the specified directory.\n")
    #    unzip_files(homework_file_paths)

def check_json_keys(json_info: Json_Info):
    """Checks if keys given in configuration JSON are of correct type, and that required keys exist in at least one instance in the global or assignment scopes.

    Args:
        json_info (Json_Info): dict of information to be checked
    """
    key_types = inspect.get_annotations(Json_Info)
    supported_languages = ("c", "cc", "java", "ml", "pascal", "ada", "lisp", "scheme", "haskell", "fortran", "ascii", "vhdl", "perl", "matlab", "python", "mips", "prolog", "spice", "vb", "csharp", "modula2", "a8086", "javascript", "plsql", "verilog")

    for key, value in key_types.items():
        for assignment in json_info:
            if hasattr(value, '__origin__') and value.__origin__ is NotRequired:
                if (type(assignment[key])) != value.__args__[0]: # first element in tuple is the type of a GenericAlias element
                    print(f'Error: The value of "{key}" must be of type {value.__args__[0]}.')
                    exit(1)
            else:
                if key not in assignment: 
                    print(f'Error: Required key "{key}" is not in configuration JSON.')
                    exit(1)
                if (type(assignment[key]) != value): 
                    print(f'Error: The value of "{key}" must be of type {value}.')
                    exit(1)
            #If language is optional, we can't assume it will be there.
            if ("language" in assignment) and (assignment["language"]).lower() not in supported_languages:
                print(f'Error: Given language "{assignment["language"]}" in assignment "{assignment["question_name"]}" is not one of the supported languages.')
                exit(1)
            if not os.path.exists(assignment["starting_path"]): #fix
                print(f'Error: "{assignment["starting_path"]}" is not a valid directory.')


def json_info_validation(config_data: Config_Data) -> list[ChainMap]:
    """Checks if configuration data is valid. If valid, returns a list of moss arguments, prioritizing assignment arguments.

    Args:
        config_data (Config_Data): dict of all information in given configuration file

    Returns:
        list[ChainMap]: if information is valid, returns a list of keys to be used in moss command
    """
    global_info = copy.copy(config_data)
    del global_info["assignment_info"]
    global_info = ChainMap(global_info)
    
    filtered_assignment_info = []

    for assignment in config_data["assignment_info"]:
        filtered_assignment_info.append(global_info.new_child(assignment))
    check_json_keys(filtered_assignment_info)

    return filtered_assignment_info

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
        moss_command.append("./moss.sh") #should be path to moss in json, defualt is ./moss.sh or something
    
    moss_command.extend(['-l', (assignment["language"]).lower()])
    moss_command.append('-d')
    if "comment" in assignment:
        moss_command.extend(['-c', (assignment["comment"])])
    if "max_appearances_before_ignored" in assignment:
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
        # puts everything in a temporary directory
        global_temp_dir = assignment["starting_path"] + "/global_temp_dir"
        # copies all files from starting path dir to global temp dir
        shutil.copytree(assignment["starting_path"], global_temp_dir)
        # unzips and flattens files
        all_paths = get_file_paths(["*"], global_temp_dir)

        unzip_files(all_paths)
        #flattened_files = get_file_paths(["*"], global_temp_dir)
        # print(flattened_files) #DELETE

        homework_file_paths = get_file_paths(assignment["submitted_files"], global_temp_dir) #strings of paths of all .c
        base_file_paths = get_file_paths(assignment["base_files"], global_temp_dir)
        moss_command = get_moss_command(assignment, homework_file_paths, base_file_paths)
        # print(moss_command)
        subprocess.run(moss_command) # .run takes a list of arguments
        shutil.rmtree(global_temp_dir) # doesn't delete global directory until moss command finishes
        # removes temporary directory

def main():
    if len(sys.argv) != 2:
        print("Usage: ./easy-moss <path to json config file>")
        exit(0) 

    try:
        config_data = get_json_info(sys.argv[1])
    except json.decoder.JSONDecodeError as err: ## fix: specific errors (ValueError, IndexError)
        print(f"Error: Given file is not properly configured as a JSON file.\n{err}")
        exit(0)
    filtered_assignment_info = json_info_validation(config_data)

    run_easy_moss(filtered_assignment_info)

main()