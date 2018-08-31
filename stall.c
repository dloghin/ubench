/**
 * Float-Int C ubench.
 *
 * Copyright (C) 2013 B. M. Tudor, D. Loghin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>

#include "common.h"


#define ITERATIONS 5000000

#define SIZE (4*1000*1000)

volatile int dummy = 0;

typedef struct
{
    unsigned char dummy[32];
}
data;


float crunch(long long iterations)
{
    long long i;
    unsigned char accum = 0;
    int index;
    data * pool = (data*)malloc(sizeof(data) * SIZE);
    if (!pool)
    {
		fprintf(stderr, "Out of memory\n");
		exit(1);
    }
    srand(2013);

	for (i = 0; i < SIZE; i++)
		pool[i].dummy[5] = i % 256;

	for (i = 0; i < iterations; i++)
	{
	    index = rand() % ( SIZE - 200);
	    accum += pool[index + 1].dummy[5];
	    accum += pool[index + 144].dummy[5];
	    accum += pool[index + 13].dummy[5];
	    accum += pool[index + 20].dummy[5];
	    accum += pool[index + 18].dummy[5];
	    accum += pool[index + 85].dummy[5];
	    accum += pool[index + 67].dummy[5];
	    accum += pool[index + 112].dummy[5];
	    accum += pool[index + 81].dummy[5];
	    accum += pool[index + 154].dummy[5];
	    accum += pool[index + 93].dummy[5];
	    accum += pool[index + 120].dummy[5];
	    accum += pool[index + 45].dummy[5];
	    accum += pool[index + 39].dummy[5];
	    accum += pool[index + 31].dummy[5];
	    accum += pool[index + 108].dummy[5];
	    accum += pool[index + 29].dummy[5];
	    accum += pool[index + 2].dummy[5];
	    accum += pool[index + 83].dummy[5];
	    accum += pool[index + 16].dummy[5];
	    accum += pool[index + 95].dummy[5];
	    accum += pool[index + 190].dummy[5];
	    accum += pool[index + 41].dummy[5];
	    accum += pool[index + 55].dummy[5];
	    accum += pool[index + 162].dummy[5];
	    accum += pool[index + 131].dummy[5];
	    accum += pool[index + 19].dummy[5];
	    accum += pool[index + 121].dummy[5];
	    accum += pool[index + 85].dummy[5];
	    accum += pool[index + 67].dummy[5];
	    accum += pool[index + 12].dummy[5];
	    accum += pool[index + 4].dummy[5];
    }
    return (float)accum;
}

int main(int argc, char ** argv)
{
	unsigned long long int t1, t2;
	long long iterations;
	int cpuid;
	float result;
	if (argc == 3)
	{
		iterations = atoll(argv[1]);
		cpuid = atoi(argv[2]);
	}
	else
	{
		if (argc == 2)
		{
			iterations = atoll(argv[1]);
			cpuid = -1;
		}
		else
		{
			iterations = ITERATIONS;
			cpuid = -1;
		}
	}

	printf("Running %s on %s %s, iterations=%lld, cpuid=%d\n", PROG, SYS, ARCH, iterations, cpuid); 
	if (cpuid >= 0)
		bind_to_core(cpuid);	
	t1 = get_time();
	result = crunch(iterations);
	t2 = get_time();
	get_iterations_per_sec(t1, t2, iterations);	
	printf("[Result %d]\n",(int)result);
	return 0;
}

