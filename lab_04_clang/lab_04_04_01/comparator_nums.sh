#!/bin/bash

if [ -z "$1" -o -z "$2" ]; then
	exit 1
else
	touch file1 file2
	reg="^[+-]?([0-9]*[.])?[0-9]+$"

	while IFS= read -r line; do
		for i in $line; do
			if [[ $i =~ $reg ]]; then
				echo $i >> file1
			fi
		done
	done < $1


	while IFS= read -r line; do
		for i in $line; do
			if [[ $i =~ $reg ]]; then
				echo $i >> file2
			fi
		done
	done < $2


	if cmp -s file1 file2; then 
		rm file1 file2
		exit 0 
	else
		rm file1 file2
		exit 1 
	fi
fi
