#WAP in Shell Scripts to find the number and sum of all integers between 100 and 200 which are divisible by 9.
#!/bin/sh
i=100
sum=0
while [ $i -le 200 ]
do
    if [ $((i%9)) -eq 0 ]
    then
        echo $i
        sum=$(($sum + $i))
    fi
    i=`expr $i + 1`
done
echo "Sum is:$sum"
