#!/bin/bash

# Check if two arguments were supplied
if [ $# -ne 2 ]; then
    echo "Error: Please supply exactly two file names as arguments."
    echo "Usage: $0 <file1> <file2>"
    exit 1
fi

# Get the contents and permissions of the files
file1=$1
file2=$2
content1=$(cat $file1)
content2=$(cat $file2)
permission1=$(ls -l $file1 | awk '{print $1}')
permission2=$(ls -l $file2 | awk '{print $1}')

# Print the contents and permissions
echo "Contents of $file1:"
echo "$content1"
echo "Permissions of $file1: $permission1"
echo ""
echo "Contents of $file2:"
echo "$content2"
echo "Permissions of $file2: $permission2"

