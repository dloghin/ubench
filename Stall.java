/**
 * Stall Java ubench.
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

import java.util.Random;

class Elements {
	char [] dummy;

	public Elements() {
		dummy = new char[32];
	}
}

public class Stall {

	private final static int ITERATIONS=5000000;

	private final static int SIZE=4*1000*1000;

	private static long crunch(long iterations) {    	
		long accum = 0;

		Elements [] pool = new Elements[SIZE];
    
		Random rand = new Random(2012);

		for (int i = 0; i < SIZE; i++) {
			pool[i] = new Elements();
			pool[i].dummy[5] = (char)(i % 256);
		}

		for (long i = 0; i < iterations; i++) {
			int index = rand.nextInt(SIZE - 200);
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

		return accum;
	}

	public static void main(String[] args) {
		long t1, t2;
		long iterations;
		long result;
		if (args.length >= 1) {	
			iterations = Long.parseLong(args[0], 10);
		}
		else {	
			iterations = Common.ITERATIONS;
		}

		System.out.printf("Stall Benchmark - iterations: %d\n", iterations); 
		t1 = Common.get_time();
		result = crunch(iterations);
		t2 = Common.get_time();
		Common.get_iterations_per_sec(t1, t2, iterations);	
		System.out.printf("[Result %d]\n", result);
	}
}
