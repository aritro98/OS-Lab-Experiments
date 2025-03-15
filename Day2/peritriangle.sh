#!/bin/bash

#2. Write a shell program to find Perimeter of a Triangle.

read -p "Enter side1:" a
read -p "Enter side2:" b
read -p "Enter side3:" c

peri=$(($a+$b+$c))

echo "Perimeter of a triangle is:$peri"
