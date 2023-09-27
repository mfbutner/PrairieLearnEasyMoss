# Easy Moss

A Wrapper for MOSS to make submissions downloaded from Prairie Learn easy :)

## Issues/Notes:

Listed are the current issues with the code, along with notes on how to fix them.

### Zip files not accounted for

- Unzip before going through files, this will create a new file
- -d might require all folders to be flattened (give different names to files w/ same name)
- -d might require all files to be in one folder (shutil)
- chain maps: if not in child, looks in parent.

#### -----GLOBAL-----

starting path: Required in one or the other
comment: Not required
number of matches to show: Not required
language: Required in one or the other
max appearances: Not Required
assignment info: Required

#### -----WITHIN ASSIGNMENT-----

question name: Required
starting path: Required in one or the other
comment: Not required
number of matches to show: Not required
language: Required in one or the other
max appearances: Not Required
submitted files: Required
base files: Not Required
are submissions by directory: not required

### Supported Langauges:

- Sort alphabetically
- Put in external file
