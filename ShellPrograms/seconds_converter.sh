#!bin/bash


while true

do

read -p  " enter the seconds   : " seconds
echo $seconds 
 
if [$seconds -lt 0 ]
 then 
 
 echo "invalid input , please enter the valid input"
 else 
 
 break 
 
fi 

done 


hours=$((seconds / 3600))

minutes=$(((seconds %3600)/60))

second=$((seconds %60))

echo " the result is $hours - $minutes - $second"

