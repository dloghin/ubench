# Run script for Java ubench. 
# 
# Copyright (C) 2013 B. M. Tudor, D. Loghin
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

#!/bin/bash

# Please set the correct path to java
JVM="java"
# Please set the correct path to java compiler
JVC="javac"


BASEDIR=$(dirname $0)
CP=$BASEDIR


if [ $# -lt 2 ]; then
	echo "Usage: $0 <bench> <cores>"
	echo "       where bench is FloatInt or Stall" 
	exit 1
fi
BENCH=$1
CORES=$(($2-1))

case $BENCH in
	"FloatInt")
		IT=5000000000
	;;
	"Stall")
		IT=500000000
	;;
	*)
		echo "Unknown benchmark $BENCH"
		exit 1
	;;
esac

# compile
if ! [ -f "$BENCH.class" ]; then
	if ! [ -f "Common.java" ]; then
		echo "Common.java not found!"
		exit 1
	fi
	if ! [ -f "$BENCH.java" ]; then
                echo "$BENCH.java not found!"
                exit 1 
        fi 
	$JVC Common.java $BENCH.java
fi  

# run
for CORE in `seq 0 $CORES` ; do
	taskset -c $CORE $JVM -cp $CP $BENCH $IT & 
done

wait
