import shlex
import subprocess
import json
import sys
from pathlib import Path

#-------NOTES-------
# *

# tell @mfbut:
# - zip files still unaccounted for.
# global options: overwritten within assignment (done)
# key is not in json if info is empty
# check if json is correctly written (done)
# unzip before going through files, this will create a new file
# -d might require all folders to be flattened (give different names to files w/ same name)

# Checks to see if the JSON file is valid.
def check_json_info(json_info):
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
    
    # Checking original instructions.
    for key in json_check_dict:
        if key not in json_info:
            print(f"Error: Required key [\"{key}\"] is not in configuration JSON file.")
            exit(0)
        if type(json_info[key]) != type(json_check_dict[key]):
            print(f"Error: Key [\"{key}\"] is not of type {type(json_check_dict[key])}")
            exit(0)
        if key == "language":
            if (json_info[key]).lower() not in supported_languages:
                print(f"Error: Given language \"{json_info[key]}\" is not one of the supported languages.")
                exit(0)
    # Checking assignment info in the JSON file.
    for assignment in json_info["assignment_info"]:
        # Checks if the required keys in assignment_info are existing and of the correct type.
        for key in json_check_dict_assignment:
            if key not in assignment:
                print(f"Error: Required key [\"assignment_info\": {key}] is not in configuration JSON file.")
                exit(0)
            if type(assignment[key]) != type(json_check_dict_assignment[key]):
                print(f"Error: Key [\"{key}\"] is not of type {type(json_check_dict_assignment[key])}")
                exit(0)
        # Checks if any of the optional keys are in assigment_info, and if they are the correct type.
        for key in json_check_dict:
            if key in assignment:
                if type(assignment[key]) != type(json_check_dict[key]):
                    print(f"Error: Key [\"{key}\"] is not of type {type(json_check_dict[key])}")
                    exit(0)
            if key == "language":
                if (assignment[key]).lower() not in supported_languages:
                    print(f"Error: Given language \"{assignment[key]}\" in \"assignment_info\" is not one of the supported languages.")
                    exit(0)
    return

# Creates a moss command as a string from info specified by user.
def get_moss_command(config_data, assignment_info, homework_file_paths, base_file_paths):
    # moss [-l language] [-d] [-b basefile1] ... [-b basefilen] [-m #] [-c "string"] file1 file2 file3 ...
    # list of arguments, " ".join
    try:
        moss_command = config_data["moss_path"]
    except:
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

# Gets info from json and stores into a nested dictionary.
def get_json_info(json_path):
    json_file = open(json_path)
    config_data = json.load(json_file)
    json_file.close()  
    return config_data

# Gets paths for all specified files from a starting directory path.
def get_file_paths(desired_files, starting_path):
    all_file_paths = []

    p = Path(starting_path).glob('**/*')
    # file = [x for x in p if x.is_file()]
    # for i in file:
    #     file_paths.append(starting_path + "/" + str(i))

    for assignment_name in desired_files:
        if assignment_name.startswith('*'):
            assignment_name = assignment_name.lstrip('*')
        p = Path(starting_path).glob('**/*' + assignment_name)
        file = [x for x in p if x.is_file()]

        for file_path in file:
            all_file_paths.append(str(file_path))

    # zip_paths = Path(starting_path).glob('**/*.zip')
    # for zip_path in zip_paths:
    #     zip_path.open() 

    return all_file_paths

def main():
    if len(sys.argv) != 2:
        print("Usage: ./easy-moss <path to json config file>")
        exit(0) 

    #Stores Json information
    try:
        config_data = get_json_info(sys.argv[1]) # config data is a dict
    except:
        print(f"Error: Given file is not properly configured as a JSON.")
        exit(0)
    check_json_info(config_data)

    #Creates and runs a moss command for each desired file
    assignment_index = 0
    for assignment_info in config_data["assignment_info"]:
        homework_file_paths = get_file_paths(assignment_info["submitted_files"], config_data["starting_path"]) #strings of paths of all .c
        base_file_paths = get_file_paths(assignment_info["base_files"], config_data["starting_path"])
        
        moss_command = get_moss_command(config_data, assignment_info, homework_file_paths, base_file_paths)
        #Runs the moss command
        # print(moss_command)
        subprocess.run(moss_command) #.run takes a list of arguments, create w/ shlex
        assignment_index += 1

main()