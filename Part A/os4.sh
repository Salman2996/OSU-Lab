#!/bin/bash

if [ "$#" -eq 0 ]
then
	echo "No name entered"
	exit
fi

for login in $*
do
	if grep $login /etc/passwd>/dev/null
	then
		echo "Login: $login"
		echo "Home directory: `grep $login /etc/passwd | cut -d ":" -f 6`"
	else
		echo "$login does not exist!"
	fi
done
