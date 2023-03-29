#!/bin/bash

echo "Enter a number: "
read number

# Find the sum of the digits
sum=0
while [ $number -gt 0 ]
do
    remainder=$(( $number % 10 ))
    sum=$(( $sum + $remainder ))
    number=$(( $number / 10 ))
done

echo "The sum of the digits is: $sum"

