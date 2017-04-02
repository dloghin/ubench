/**
 * Common auxiliary functions for ubench.
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
#define _GNU_SOURCE             /* See man 7 feature_test_macros */
#define __USE_GNU
#include "common.h"

#define ARRAY_SIZE 4096
#define STRIDE 64
#define ITERATIONS 5000000
#define REPORT 250000

unsigned long long int get_time()
{
#if defined __linux__ && !defined __arm__
	/* Linux intel */
	struct timespec tp;
	assert(clock_gettime(CLOCK_REALTIME, &tp) == 0);
	return (unsigned long long int)(tp.tv_nsec + tp.tv_sec * 1000000000);
#else
	/* Default, should work on any platform */
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (unsigned long long int)(tv.tv_usec + tv.tv_sec * 1000000);
#endif
	
}

void get_iterations_per_sec(unsigned long long int t1, unsigned long long int t2, long long int iter)
{
#if defined __linux__ && !defined __arm__
	double opsns = ((double)iter)/(t2-t1);
	double opss = opsns * 1000000000.0;
	printf("Time %llu nsec, Iterations/nsec %3.4lf, Iterations/sec %3.4lf, MITPS %3.4lf\n", (t2-t1), opsns, opss, opss/1000000.0);
#else
	double opsus = ((double)iter)/(t2-t1);
	double opss = opsus * 1000000.0;
	printf("Time %llu usec, Iterations/usec %3.4lf, Iterations/sec %3.4lf, MITPS %3.4lf\n", (t2-t1), opsus, opss, opss/1000000.0);
#endif
}

void bind_to_core(int coreid)
{
#ifndef __MACH__
	int result;
	cpu_set_t set;
	
	CPU_ZERO(&set);
	CPU_SET(coreid, &set);

	result = sched_setaffinity(getpid(), sizeof(cpu_set_t), &set);
	if (result)
	{
		switch(errno)
		{
			case EFAULT:
				perror("sched_setaffinity error EFAULT");
				break;
			case EINVAL:
				perror("sched_setaffinity error EINVAL");
				break;
			case EPERM:
				perror("sched_setaffinity error EPERM");
				break;
			case ESRCH:
				perror("sched_setaffinity error ESRCH");	
				break;
			default:
				perror("sched_setaffinity error wierd errno");
				break;
		}
		exit(1);
	}
	fprintf(stdout, " *** Affinity set to core id=%d\n", coreid);
#endif
}


