#!/bin/bash

if [ -z $1 ]; then
    exit 1
fi

touch ../../temp_out

../../app.exe < $1 > ../../temp_out

if [[ $? =~ 1 ]]; then
    exit 0
else
    exit 1
fi 

