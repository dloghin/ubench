/**
 * Common auxiliary methods for ubench.
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

#ifndef __COMMON_H___
#define __COMMON_H___

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <sched.h>
#include <sys/types.h>
#include <errno.h>
#include <assert.h>

unsigned long long int get_time();

void get_iterations_per_sec(unsigned long long int, unsigned long long int, long long int);

void bind_to_core(int);

#endif

