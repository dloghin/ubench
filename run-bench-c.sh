# Run script for C(native) ubench. 
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

BASEDIR=$(dirname $0)
CP=$BASEDIR

if [ $# -lt 2 ]; then
	echo "Usage: $0 <bench> <cores>"
	echo "       where bench is floatint or stall" 
	exit 1
fi
BENCH=$1
CORES=$(($2-1))

case $BENCH in
	"floatint")
		IT=5000000000
	;;
	"stall")
		IT=500000000
	;;
	*)
		echo "Unknown benchmark $BENCH"
		exit 1
	;;
esac

# compile
if ! [ -e "$BENCH.exe" ]; then
	make $BENCH
fi 

# run
for CORE in `seq 0 $CORES` ; do
	taskset -c $CORE ./$BENCH.exe $IT & 
done

wait
