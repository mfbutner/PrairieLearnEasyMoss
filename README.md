# Easy Moss

A Wrapper for MOSS to make submissions downloaded from Prairie Learn easy :)

## Issues/Notes:
Listed are the current issues with the code, along with notes on how to fix them.

### Zip files not accounted for
* Unzip before going through files, this will create a new file
* -d might require all folders to be flattened (give different names to files w/ same name)
* -d might require all files to be in one folder (shutil)

### Checking if input JSON is formatted properly
* Current method does not account for optional arguments in global scope
* Clear up what keys are required or optional for each scope

#### -----GLOBAL-----
starting path:
comment:
num assignments
number of matches to show:
language:
max appearances:
submitted files:
base files:
assignment info: required
are submissions by directory: not required

#### -----WITHIN ASSIGNMENT-----
starting path:
comment:
num assignments
number of matches to show:
language:
max appearances:
submitted files:
base files:
are submissions by directory: not required

### Adding -d to MOSS command
* If the "are_submissions_by_directory" key is not there at all, add -d
* If the key is True, add -d