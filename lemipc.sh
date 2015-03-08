#!/bin/bash

COUNTER=0

while [ $COUNTER -lt $1 ]; do
    echo $COUNTER
    ./lemipc
    let COUNTER=COUNTER+1
    echo $COUNTER
done
