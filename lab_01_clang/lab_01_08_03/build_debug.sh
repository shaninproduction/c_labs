#!/bin/bash

if [ ! -f ./main.c ]; then
    echo Error: No main.c file.
    exit 1
fi 

gcc -c -O0 -g3 main.c
gcc main.o -o app.exe