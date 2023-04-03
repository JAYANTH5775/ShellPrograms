#!/bin/bash

# Check if the directory path is provided as input
if [ -z "$1" ]; then
    echo "Please provide a directory path as input."
    exit 1
fi

# Check if the directory exists
if [ ! -d "$1" ]; then
    echo "Directory not found."
    exit 1
fi

# Count the number of subdirectories
subdirs=$(find "$1" -type d -mindepth 1 | wc -l)

echo "The number of subdirectories in $1 is: $subdirs."

