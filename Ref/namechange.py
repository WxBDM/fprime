# -*- coding: utf-8 -*-
"""
Brandon Molyneaux

this does stuff. cool.
"""

# command line equiv:
#mv TempSimComponentImpl.hpp-template TempSimComponentImpl.hpp

import os
import sys

cwd = os.getcwd()

# check to make sure directory and file name is there.
if len(sys.argv) < 2:
    print("Must have directory and at least one file name.")
    exit()
if len(sys.argv) == 2:
    print("Must include at least one file.")
    exit()
    
# checks to see if it's a valid directory.
directory = sys.argv[1]
full_dir = os.path.join(cwd, directory)

# specifically, check to see if it's a file (extra information)
# checks if it's cpp, hpp, or xml (current known files in these dirs)
is_file = full_dir.lower().endswith(('.cpp', '.xml', '.hpp'))
if is_file:
    print('{} is a {}')

if not os.path.isdir(full_dir):
    print("{} is not a directory in Ref.".format(full_dir))
    exit()
    
# iterate through files.
for file in sys.argv[2:]:
    file_dir = os.path.join(full_dir, file)
    # check to ensure file actually exists.
    if not os.path.isfile(file_dir):
        print('{} file not found.'.format(file_dir))
        exit()
        
    fileName = file.split(".")[0][:-2] # removes Ai from filename
    
    # Checks to ensure the cpp-template files are there.
    
    extensions = ['cpp', 'hpp']
    for extension in extensions:
        f_template = os.path.join(full_dir, fileName + "Impl.{}-template".format(extension))
        
        if not os.path.isfile(f_template):
            print("{} was expected, not found.".format(f_template))
            exit()
        
        template_rename = os.path.join(full_dir, fileName + "Impl.{}".format(extension))
        
        try:
            os.rename(f_template, template_rename)
        except:
            print("Unsucessful name change for {} file.".format(extension))
            exit()
        
        print("Successfully changed {} to {}".format(fileName + "Impl.cpp-template", fileName + "Impl.cpp"))

        
