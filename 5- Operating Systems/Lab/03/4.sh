#!/bin/bash

echo "enter name of file"
read file
echo "enter x"
read x
echo "enter y"
read y
tail -n +$x $file | head -n $(($y-$x+1))