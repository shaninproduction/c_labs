#!/bin/bash

if [ ! -f ./main.c ]; then
    echo Error: No main.c file.
    exit 1
fi 

gcc -c -Werror -Wall -std=c99 -Wpedantic -Wextra -Wfloat-equal main.c -lm
gcc -Werror -Wall -std=c99 -Wpedantic -Wextra -Wfloat-equal main.o -o app.exe -lm
