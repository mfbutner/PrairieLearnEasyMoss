import subprocess
import json
import sys

# ask butner:
# do we assume that people do all the right inputs for language? (check for incorrect input)
# ask abt command line formatting
# if there's no base file is the dict empty or is base file not in the json at all?
# how should we know -d is neccessary? (zip file or no)
# should the path to base files be given? same folder as everything else or not?

def get_moss_command(assignment_info, start_file):
    # moss [-l language] [-d] [-b basefile1] ... [-b basefilen] [-m #] [-c "string"] file1 file2 file3 ...
    moss_command = "moss"
    moss_command += (" -l " + (assignment_info["language"]).lower())
    if assignment_info["submitted_files"]:
        moss_command += (" -d " + (assignment_info["submitted_files"]).lower())
    if assignment_info["base_files"]: # if a list is empty its false?
        for file in base_files:
            moss_command += (" -b" + file)
    moss_command += (" -m " + assignment_info["max_appearances_before_ignored"])
    moss_command += (" -c " + assignment_info["comment"])
    moss_command += start_file
    return moss_command    

def get_json_info(json_path):
    # Gets info from json and stores into a nested dictionary
    json_file = open(json_path)
    config_data = json.load(json_file)
    json_file.close()  
    return config_data

def main():
    if len(sys.argv) != 3:
        print("Usage: ./easy-moss <path to json config file> <path to file containing homework files>")
        exit(0)  
    subprocess.Popen('find ' + sys.argv[2] + ' -type f -name "*.c" > all-file-paths.txt', shell=True)
    infile = open("all-file-paths.txt", "r")
    all_file_paths = []
    for line in infile:
        line = line.strip()
        all_file_paths.append(line)
    infile.close()
    subprocess.Popen('rm all-file-paths.txt', shell=True)
    config_data = get_json_info(sys.argv[1])
    assignment_index = 0
    for assignment in config_data["assignment_info"]:
        moss_command = get_moss_command(assignment, all_file_paths[assignment_index])
        #Runs the moss command
        subprocess.Popen(moss_command, shell=True)
        assignment_index += 1

main()