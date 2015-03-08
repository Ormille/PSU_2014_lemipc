#!/bin/bash

COUNTER=0

if [ $1 ]; then
    while [ $COUNTER -lt $1 ]; do
	echo "Counter": $COUNTER
	./lemipc &
	let COUNTER=COUNTER+1
	echo $COUNTER
    done
else
    while [ $COUNTER -lt 2 ]; do
	echo "Counter": $COUNTER
	./lemipc &
	let COUNTER=COUNTER+1
	echo $COUNTER
    done
fi
