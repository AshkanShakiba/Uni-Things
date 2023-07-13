#!/bin/bash

while(true)
do
echo "enter the number"
read a
out=0
sum=0
while [ $a -gt 0 ]
do
    out=$(expr $out \* 10)
    digit=$(expr $a % 10)
    out=$(expr $out + $digit)
    a=$(expr $a / 10)
    sum=$(expr $sum + $digit)
done
echo "reverse is $out"
echo "sum of digits is $sum"
done
