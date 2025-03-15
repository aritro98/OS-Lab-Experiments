#!/bin/bash
#1) WAP to check, if the given number is even or odd

read -p "Enter a number:" num
if [ $((num % 2)) -eq 0 ]
then 
    echo "Even number"
else
    echo "Odd number"
fi
