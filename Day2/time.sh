# !/bin/bash

#3. Write a shell program to convert given seconds in hours, minutes and seconds.

read -p "Enter time in seconds:" s

h=$(echo "$s/3600" | bc)
m=$(echo "($s%3600)/60" | bc)
s=$(echo "($s%3600)%60" | bc)

echo "Hours:$h Minutes:$m Seconds:$s"
