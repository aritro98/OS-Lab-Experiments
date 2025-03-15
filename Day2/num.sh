#!/bin/bash

# Take input from user and calculate sum.
read -p "Enter first number: " num1
read -p "Enter second number: " num2
 
# Calculate sum
sum=$(( $num1 + $num2 ))

# Display the result
echo "Sum is: $sum" 
