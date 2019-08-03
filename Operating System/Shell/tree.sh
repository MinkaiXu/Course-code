#!/bin/bash

function list()
{
	for file in `ls -B $1`
	# show all files and dirs in current dir
	do
		if [ -d "$1/$file" ]
		then
			echo "$2$file"
			# call list recursively if it’s a dir
			list "$1/$file" "    $2"
		else
			echo "$2$file"
		fi
	done
}

list $1 '    '
