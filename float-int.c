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

#include "common.h"

#define ITERATIONS 5000000

volatile int dummy = 0;

int crunch(long long iterations)
{
	float a0, a1, a2, a3, a4, a5, a6, a7;
	int q0, q1, q2, q3, q4, q5, q6, q7;
	long long i = 0;

	a0 = 1;
	a1 = 1;
	a2 = 2;
	a3 = 3;

	a4 = 1;
	a5 = 1;
	a6 = 2;
	a7 = 3;

	q0 = 1.01;
	q1 = 1.02;
	q2 = 1.03;
	q3 = 1.04;

	q4 = 1.06;
	q5 = 1.22;
	q6 = 1.23;
	q7 = 1.50;

	for ( i=0; i<iterations; i++)
	{
		a0 = a1 + a2;
		a1 = a2 + a3;
		a2 = a3 + a4;
		a3 = a4 + a5;
		a5 = a6 * a7;
		a7 = a1 / a0;

		q0 = q1 + q2;
		q1 = q2 + q3;
		q2 = q3 + q4;
		q3 = q4 + q5;
		q5 = q6 * q7;
		q7 = q1 / q0;

	} 
	return a0 + a3 + a6 + q0 + q1;

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


