#!/bin/bash
#To display the arguments in reverse

if [ "$#" -eq 0 ]
then
	echo "No arguments found!"
exit
fi

rev=""

echo "Number of arguments are: $#"
echo "The arguments are: $*"
echo "The arguments in reverse are: "

for i in $*
do
	rev=$i" "$rev
done
echo $rev
