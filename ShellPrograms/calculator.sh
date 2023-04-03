#!bin/bash 
if [$# -ne 4]; then
echo "enter the vlaid 4 numbers of a , b, c, d "
exit 1
fi

a=$1
b=$2
c=$3 
d=$4

result=$((a*20 -b*2 +c*d))
echo "result is : $result"

