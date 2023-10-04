#!/bin/bash

if [ ! -f ./main.c ]; then
    echo Error: No main.c file.
    exit 1
fi 

clang -c -fsanitize=address -fno-omit-frame-pointer -O0 -g3 main.c
clang -fsanitize=address -fno-omit-frame-pointer -g main.o -o app.exe