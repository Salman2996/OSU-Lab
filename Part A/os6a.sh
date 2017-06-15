#!/bin/bash

echo "Enter number 1: "
read n1
echo "Enter number 2: "
read n2
echo "Enter number 3: "
read n3

if [ $n1 -gt $n2 ]; then
	if [ $n1 -gt $n3 ]; then
		echo "Greatest: $n1"
	else
		echo "Greatest: $n3"
	fi
else
	if [ $n2 -gt $n3 ]; then
		echo "Greatest: $n2"
	else
		echo "Greatest: $n3"
	fi
fi
