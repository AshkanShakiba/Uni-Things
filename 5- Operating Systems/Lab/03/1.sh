#!/bin/bash

echo "enter the first number"
read a
if [[ -n ${a//[0-9]/} ]]; then
    echo "not a number"
    exit 1
fi
echo "enter the second number"
read b
if [[ -n ${b//[0-9]/} ]]; then
    echo "not a number"
    exit 1
fi
let sum=a+b
echo "sum is $sum"
if [[ $a -gt $b ]]; then
    echo "$a is greater than $b"
elif [[ $a -lt $b ]]; then
    echo "$a is less than $b"
else
    echo "$a is equal to $b"
fi