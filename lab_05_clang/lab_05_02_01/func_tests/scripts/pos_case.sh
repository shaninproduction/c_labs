#!/bin/bash

if [ -z $1 -o -z $2 ]; then
    exit 1
fi

../../app.exe $1 > ../../temp_out
./comparator_nums.sh ../../temp_out $2

if [[ $? =~ 0 ]]; then
    exit 0
else
    exit 1  
fi 
