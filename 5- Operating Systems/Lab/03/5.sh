#!/bin/bash

echo "enter the number"
read a
case $a in
    1) 
        for ((i=1; i<=5; i++)); do 
            for ((j=1; j<=i; j++)); do 
                echo -n $i
            done
            echo
        done
        echo
    ;;
    2)
        for ((i=0; i<6; i++)); do 
            for ((j=0; j<5-i; j++)); do 
                echo -n " "  
            done
            for ((j=0;j<i+1;j++)); do
                echo -n "."
                echo -n " "
            done
            echo
        done
        for ((i=0; i<5; i++)); do 
            for ((j=0; j<i+1; j++)); do 
                echo -n " "  
            done
            for ((j=0;j<5-i;j++)); do
                echo -n "."
                echo -n " "
            done
            echo
        done
    ;;
    3)
        for ((i=0;i<5;i++)); do
            echo -n "|"
            for ((j=0;j<i;j++)); do 
                echo -n " |"
            done
            echo "_"
        done
    ;;
    *) echo "invalid number"
    ;;
esac