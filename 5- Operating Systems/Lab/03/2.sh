#!/bin/bash

while(true)
do
echo "enter the first number"
read a
echo "enter the operator"
read op
echo "enter the second number"
read b
case $op in
    +) let sum=a+b
        echo "sum is $sum"
        ;;
    -) let sum=a-b
        echo "sum is $sum"
        ;;
    /) let sum=a/b
        echo "sum is $sum"
        ;;
    x) let sum=a*b
        echo "sum is $sum"
        ;;
    *) echo "invalid operator"
        ;;
esac
done
