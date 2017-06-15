#!/bin/bash

echo -e "Enter the password: "
stty -echo
read pass1
echo -e "Retype password: "
read pass2

if [ $pass1 = $pass2 ]; then
	tput clear
	echo -e "Terminal locked"
	echo -e "Enter password to unlock: "
	read pass3

	while [ $pass1 != $pass3 ]
	do
		echo -e "Wrong password! Enter password to unlock: "
		read pass3
	done
	echo -e "Terminal unlocked"
else
	echo -e "Cannot lock terminal"
fi
stty echo
