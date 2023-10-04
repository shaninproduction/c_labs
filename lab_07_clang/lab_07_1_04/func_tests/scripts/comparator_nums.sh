#/bin/bash
if [ -z "$1" -o -z "$2" ]; then
	exit 1

else

if cmp -s $1 $2; then 
		exit 0 
	else
		exit 1 
	fi
fi