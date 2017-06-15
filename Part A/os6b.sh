#!/bin/bash

echo "Enter string: "
read s

len=${#s}
rev=""

for (( i=len-1; i>=0 ;i-- ))
do
	rev="$rev${s:$i:1}"
done
echo $rev
