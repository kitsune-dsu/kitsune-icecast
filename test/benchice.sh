#!/bin/sh

# $1 - the directory containing slaptest
# $2 - the file to write the time to
# $3 - the number of operations to perform

/usr/bin/time -f "%e" $1/icecast-performance.sh $3 2> $2