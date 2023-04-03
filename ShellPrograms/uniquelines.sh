#!/bin/bash

# Check if the file name is provided as input
if [ -z "$1" ]; then
    echo "Please provide a file name as input."
    exit 1
fi

# Check if the file exists
if [ ! -f "$1" ]; then
    echo "File not found."
    exit 1
fi

# Remove duplicate lines from the file
sort -u "$1" -o "$1"

echo "Duplicate lines have been removed from $1."

