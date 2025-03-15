#!/bin/bash

#1. Write a shell program to find area of a circle.

read -p "Enter the radius of the circle:" r
area=$(echo "3.14*$r*$r" | bc)
echo "Area of the circle is:$area"
