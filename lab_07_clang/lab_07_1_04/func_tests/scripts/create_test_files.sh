#!/bin/bash

if [ -z $1 -o -z $2 ]; then
    exit 1
fi

for ((i = 1; i <= $2; i++))
{
    if [ $1 = "pos" ]; then

        if [ $i -lt 10 ]; then
            touch ../data/pos_0${i}_args.txt
            touch ../data/pos_0${i}_in.txt
            touch ../data/pos_0${i}_out.txt
        else
            touch ../data/pos_${i}_args.txt
            touch ../data/pos_${i}_in.txt
            touch ../data/pos_${i}_out.txt
        fi
    fi

    if [ $1 = "neg" ]; then

        if [ $i -lt 10 ]; then
            touch ../data/neg_0${i}_args.txt
            touch ../data/neg_0${i}_in.txt
            touch ../data/neg_0${i}_out.txt

        else
            touch ../data/neg_${i}_args.txt
            touch ../data/neg_${i}_in.txt
            touch ../data/neg_0${i}_out.txt
        fi
    fi
}