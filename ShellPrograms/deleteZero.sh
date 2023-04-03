#!/bin/bash

# Check if the directory name is provided as input
if [ -z "$1" ]; then
    echo "Please provide a directory name as input."
    exit 1
fi

# Check if the directory exists
if [ ! -d "$1" ]; then
    echo "Directory not found."
    exit 1
fi

# Delete all files with size 0 bytes
find "$1" -type f -size 0 -delete

echo "All files with size 0 bytes have been deleted from $1."

