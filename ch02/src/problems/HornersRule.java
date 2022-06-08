package problems;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class HornersRule {
	
	public static double hornersRule(double[] coeffs, double x) {
		double y = 0;
		for (int i = coeffs.length - 1; i >= 0; i--)
			y = coeffs[i] + x * y;
		return y;
	}
	
	public static double[] inputCoeffs() {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		double[] coeffs;
		int n = 0;
		
		System.out.println("Please input the degree of the polynomial (n): ");
		try {
			n = Integer.parseInt(br.readLine()) + 1;
		} catch(NumberFormatException | IOException nfe) {
			System.err.println("Invalid Format!");
		}
		
		coeffs = new double[n];
		
		System.out.format("Please enter the coefficients in order a0, a1, ..., a%d: ", n);
		for (int coeff = 0; coeff < n; coeff++) {
			try {
				coeffs[coeff] = Double.parseDouble(br.readLine());
			} catch(NumberFormatException | IOException nfe) {
				System.err.println("Invalid Format!");
			}
		}
		
		return coeffs;
	}
	
	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		double[] coeffs;
		double x = 0.0;
		
		System.out.println("This is Horner's rule for evaluating a polynomial.");
		coeffs = inputCoeffs();
		System.out.print("Please enter a value for x: ");
		try {
			x = Double.parseDouble(br.readLine());
		} catch(NumberFormatException | IOException nfe) {
			System.err.println("Invalid Format!");
		}
		
		System.out.format("For f(x) = %f", coeffs[0]);
		for (int i = 1; i < coeffs.length; i++)
			System.out.format((coeffs[i] > 0.0 ? " + " : " ") + "%fx^%d", coeffs[i], i);
		System.out.format(",\nResult f(%f) = %f", x, hornersRule(coeffs, x));
	}
}
