#!/bin/bash

if [ -z $1 ]; then
    exit 1
fi

params=""

while read temp
do
params+=" $temp"
done < $1

cd ../..

./app.exe$params

if [[ $? != 0 ]]; then
    exit 0
else
    exit 1
fi 

