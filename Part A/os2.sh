#!/bin/bash
#To check if 2 files have the same permissions
a=$1
b=$2
set -- `ls -l $1`
x=$1
set -- `ls -l $b`
y=$1

if [ $x = $y ]; then
echo "Equal"
echo $x
else
echo "Not equal"
echo "$a	$x"
echo "$b	$y"
fi
