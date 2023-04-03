#!/bin/bash

# Check if the script was called with two arguments
if [ $# -ne 2 ]; then
  echo "Usage: $0 <start> <end>"
  exit 1
fi

# Assign the arguments to variables
start=$1
end=$2

# Use a while loop to print the numbers from start to end inclusive
while [ $start -le $end ]; do
  echo $start
  start=$((start+1))
done



