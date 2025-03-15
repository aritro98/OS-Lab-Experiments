#!/bin/bash
#3) Input 3 integers and find the largest one

read -p "Enter a 1st number:" num1
read -p "Enter a 2nd number:" num2
read -p "Enter a 3rd number:" num3
if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]
then
    echo "$num1 is greatest"
elif [ $num2 -gt $num2 ] && [ $num2 -gt $num3 ]
then
    echo "$num2 is greatest"
else
    echo "$num3 is greatest"
fi
