#!/bin/bash

if [ ! -f ./main.c ]; then
    echo Error: No main.c file.
    exit 1
fi 

clang -fsanitize=memory -fno-omit-frame-pointer -c -O0 -g3 main.c
clang -fsanitize=memory -fno-omit-frame-pointer -g main.o -o app.exe