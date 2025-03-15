#!/bin/bash
#2) Input a year and check, if the given year is leap or not

read -p "Enter a year:" yr
if [ $((yr % 4)) -eq 0 ] && [ $((yr % 100)) -ne 0 ]
then
    echo "Leap Year"
elif [ $((yr % 400)) -eq 0 ]
then
    echo "Leap Year"
else
    echo "Not a Leap Year"
fi
