#!/bin/bash
#4) WAP to enter the mark of a student and find the grades

read -p "Enter the marks of a student:" marks
if [ $marks -ge 90 ] && [ $marks -le 100 ]
then
    echo "O Grade"
elif [ $marks -ge 80 ] && [ $marks -lt 90 ]
then
    echo "E Grade"
elif [ $marks -ge 70 ] && [ $marks -lt 80 ]
then
    echo "A Grade"
elif [ $marks -ge 60 ] && [ $marks -lt 70 ]
then
    echo "B Grade"
elif [ $marks -ge 50 ] && [ $marks -lt 60 ]
then
    echo "C Grade"
elif [ $marks -ge 40 ] && [ $marks -lt 50 ]
then
    echo "D Grade"
else
    echo "F Grade"
fi
