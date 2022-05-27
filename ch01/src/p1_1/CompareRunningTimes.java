package p1_1;

import java.lang.Math.*;

public class CompareRunningTimes {
	static double runtimes[] = {1.0, 6.0E1, 3.6E3, 8.64E4, 2.592E6, 3.1536E7, 3.1536E9};
	
	public static double factorial(double n) {
		int fact = (int)n, multiplier = (int)n;
		while (multiplier > 0) {
			fact = fact * multiplier;
			multiplier--;
		}
		
		return fact;
	}
 	
	public static void printRuntimes() {
		// lg(n) time
		System.out.print("lg(n)\t\t");
		for (double time : runtimes)
			System.out.format("%.5e\t\t", time / ((Math.log(1E-6) / Math.log(2))));
		System.out.print('\n');
		
		// sqrt(n) time
		System.out.print("sqrt(n)\t\t");
		for (double time : runtimes)
			System.out.format("%.5e\t\t", time / Math.sqrt(1E-6));
		System.out.print('\n');
		
		// linear time
		System.out.print("n\t\t");
		for (double time : runtimes)
			System.out.format("%.5e\t\t", time / 1E-6);
		System.out.print('\n');
		
		// n(lg(n)) time
		System.out.print("n(lg(n))\t");
		for (double time : runtimes)
			System.out.format("%.5e\t\t", time / (1E-6 * (Math.log(1E-6) / Math.log(2))));
		System.out.print('\n');
		
		// quadratic time
		System.out.print("n^2\t\t");
		for (double time : runtimes)
			System.out.format("%.5e\t\t", time / Math.pow(1E-6, 2));
		System.out.print('\n');
		
		// cubic time
		System.out.print("n^3\t\t");
		for (double time : runtimes)
			System.out.format("%.5e\t\t", time / Math.pow(1E-6, 3));
		System.out.print('\n');
		
		// 2^n time
		System.out.print("2^n\t\t");
		for (double time : runtimes)
			System.out.format("%.5e\t\t", time / Math.pow(2, 1E-6));
		System.out.print('\n');
		
		// n! time
		System.out.print("n!\t\t");
		for (double time : runtimes)
			System.out.format("%.5e\t\t", time / factorial(1E-6));
		System.out.print('\n');
	}
	
	public static void main(String args[]) {
		System.out.print("Comparison of running times for the largest problem size n of a problem,");
		System.out.print("that can be solved in time t,\nassuming that the algorithm to solve the problem");
		System.out.print("takes f(n) microseconds:\n\n---------------------------------------------------");
		System.out.print("-------------------------------------------------------------------------------------------");
		System.out.print("------------------------------\n");
		System.out.print("f(n)\t\t1 second\t\t1 minute\t\t1 hour\t\t\t1 day\t\t\t1 month\t\t\t1 year\t\t\t1 century\n");
		System.out.print("___________________________________________________________________________________________");
		System.out.print("_________________________________________________________________________________\n");
		printRuntimes();
	}
}