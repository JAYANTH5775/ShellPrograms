#!bin/bash 
for ((counter = 0 ; counter<=10;counter++))
do
echo -n "$counter"
printf "\n"
done 
printf "\n"

echo "enter your name "
read name -p 
echo "$name welcome to the shell programming"


echo "enter the number " 
read -p num  

if $num -gt 10 
echo " the number is greater the 10 "
else 
echo "number is less then 10"
done 
