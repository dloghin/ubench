/**
 * Float-Int Java ubench.
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

public class FloatInt {

	private final static int ITERATIONS=5000000;

	private static int crunch(long iterations) {
		int a0, a1, a2, a3, a4, a5, a6, a7;
		double q0, q1, q2, q3, q4, q5, q6, q7;
		long i = 0;

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

		for ( i=0; i<iterations; i++) {
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
		return a0 + a3 + a6 + (int)Math.round(q0) + (int)Math.round(q7);
	}	

	public static void main(String[] args) {
		long t1, t2;
		long iterations;
		int result;
		if (args.length >= 1) {	
			iterations = Long.parseLong(args[0], 10);
		}
		else {	
			iterations = Common.ITERATIONS;
		}

		System.out.printf("FloatInt Benchmark - iterations: %d\n", iterations); 
		t1 = Common.get_time();
		result = crunch(iterations);
		t2 = Common.get_time();
		Common.get_iterations_per_sec(t1, t2, iterations);	
		System.out.printf("[Result %d]\n", result);
	}
}


