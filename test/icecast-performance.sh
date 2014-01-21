#!/bin/bash
if [ -z "$1" ] 
then
    echo "Usage: `basename $0`  <nr_clients>"
    exit 1
fi

for (( i=1; i < 8; i++ )); do 
     for (( j=0; j < $1; j++ )); do 
        wget -O /dev/null http://localhost:23000/file$i.ogg &> /dev/null &
     done
     wait
     echo "done " $i
done
