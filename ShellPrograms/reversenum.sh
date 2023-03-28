#!bin/bash 
read -p "enter the number " num
str = " "
while num!=0
do
remainder = num%10 
str = str + remainder
num = num/10
done
echo $str
