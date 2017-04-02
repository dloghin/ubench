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

public class Common {

	public final static int ARRAY_SIZE = 4096;
	public final static int STRIDE = 64;
	public final static int ITERATIONS = 5000000;	
	public final static int REPORT = 250000;

	public static long get_time() {
		return System.currentTimeMillis();
	}
	
	public static void get_iterations_per_sec(long t1, long t2, long iter) {
		double tsec = (t2-t1) / 1000.0;
		double mitps = iter/((t2-t1)*1000.0);
		System.out.printf("Time %.0f sec, MITPS %.0f\n", tsec, mitps);
	}

}


