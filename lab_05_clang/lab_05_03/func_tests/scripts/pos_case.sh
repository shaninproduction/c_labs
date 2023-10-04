#!/bin/bash

if [ -z $1 -o -z $2 -o -z $3 ]; then
    exit 1
fi

params=""

while read temp
do
params+=" $temp"
done < $3

gcc t2b.c -o t2b && ./t2b $1

../../app.exe$params > ../../temp_out
./comparator_nums.sh ../../temp_out $2

if [[ $? =~ 0 ]]; then
    rm t2b
    rm bfile.bin
    exit 0
else
    rm t2b
    rm bfile.bin
    exit 1
fi 
