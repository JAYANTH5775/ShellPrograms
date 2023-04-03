#!bin/bash 

hour = $((date+%H ))

if [$hour -lt 12]
then 
echo "Good morning" 


elif [$hour -lt 18]
then 
echo "good afternooon"


else
echo "Good Evening"
fi 

