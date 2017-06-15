#!/bin/bash

if [ "$#" -ne 1 ]
then
	echo "No arguments"
	exit
fi

if [ ! -d "$1" ]
then
	echo "Does not exist"
	exit
fi

echo "Max length directory in $1 is:"
x=$1

cd $1
set -- `ls -lR | grep -v "^d" | sort -k 5 -rn`
echo -e "Length: $5 	Directory: $9"
