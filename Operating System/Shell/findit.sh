#!/bin/sh

if [ $# -eq 1 ]  # without dir, use current dir as default dir
then
	find . -name "*.c" -o -name "*.h" | xargs grep "$1"
	# find: find all .h or .c files
	# grep: search searchstring in these files
else
	count=`ls $1 | wc -l`
	# calculate the number of files
	if [ "$count" -eq 0 ]
	then
		echo "Empty dir!"
	else
		find $1 -name "*.c" -o -name "*.h" | xargs grep "$2"
	fi
fi
