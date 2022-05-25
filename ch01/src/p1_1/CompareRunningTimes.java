package p1_1;

import java.lang.Math.*;

public class CompareRunningTimes {
	static double runtimes[] = {1.0, 6.0E1, 3.6E3, 8.64E4, 2.592E6, 3.1536E7, 3.1536E9};
	
	public static int factorial(int n) {
		int fact = n, multiplier = n;
		while (multiplier > 0) {
			fact = fact * multiplier;
			multiplier--;
		}
		
		return fact;
	}
 	
	public static void printRuntimes() {
		// lg(n) time
		System.out.print("n\t");
		for (double time : runtimes) {
			System.out.print((Math.log(time) / Math.log(2)) * 1E6);
			System.out.print("\t\t");
		}
		System.out.print('\n');
		
		// sqrt(n) time
		System.out.print("n\t");
		for (double time : runtimes) {
			System.out.print(Math.sqrt(time) * 1E6);
			System.out.print("\t\t");
		}
		System.out.print('\n');
		
		// constant time
		System.out.print("n\t");
		for (double time : runtimes) {
			System.out.print(time * 1E6);
			System.out.print("\t\t");
		}
		System.out.print('\n');
		
		// n(lg(n)) time
		System.out.print("n\t");
		for (double time : runtimes) {
			System.out.print(time * (Math.log(time) / Math.log(2)) * 1E6);
			System.out.print("\t\t");
		}
		System.out.print('\n');
				
		// linear time
		System.out.print("n\t");
		for (double time : runtimes) {
			System.out.print(time * 1E6);
			System.out.print("\t\t");
		}
		System.out.print('\n');
		
		// quadratic time
		System.out.print("n\t");
		for (double time : runtimes) {
			System.out.print(Math.pow(time, 2) * 1E6);
			System.out.print("\t\t");
		}
		System.out.print('\n');
		
		// cubic time
		System.out.print("n\t");
		for (double time : runtimes) {
			System.out.print(Math.pow(time, 3) * 1E6);
			System.out.print("\t\t");
		}
		System.out.print('\n');
		
		// 2^n time
		System.out.print("n\t");
		for (double time : runtimes) {
			System.out.print(Math.pow(2, time) * 1E6);
			System.out.print("\t\t");
		}
		System.out.print('\n');
		
		// n! time
		System.out.print("n\t");
		for (double time : runtimes) {
			System.out.print(factorial((int)time) * 1E6);
			System.out.print("\t\t");
		}
		System.out.print('\n');
	}
	
	public static void main(String args[]) {
		System.out.print("Comparison of running times for the largest problem size n of a problem,");
		System.out.print("that can be solved in time t,\nassuming that the algorithm to solve the problem");
		System.out.print("takes f(n) microseconds:\n\n---------------------------------------------------");
		System.out.print("-----------------------------------------------------------------------------\n");
		System.out.print("f(n)\t1 second\t1 minute\t1 hour\t\t1 day\t\t1 month\t\t1 year\t\t1 century\n");
		System.out.print("_______________________________________________________________________________");
		System.out.print("_________________________________________________\n");
		printRuntimes();
	}
}