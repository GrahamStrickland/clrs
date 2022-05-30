// Linear-Search algorithm from ex2.1-3 p.22 of CLRS 3e

package ch02;

public class LinearSearch {
	public static int linearSearch(int[] A, int nu) {
		int j = 0;
		
		while (j != A.length) {
			if (A[j] == nu) 
				return j;
			else
				j += 1;
		}
		return -1;
	}
	
	public static void testLinearSearch(int[] A, int nu) {
		// Test Linear-Search algorithm with array A.
		System.out.print("Array values: ");
		
		for (int i : A) {
			System.out.print(i);
			System.out.print(' ');
		}
		System.out.format("\nnu = %d\n", nu);
		
		System.out.format("Array does"+(linearSearch(A, nu)==-1?" not ":" ")+"contain %d.\n\n", nu);
	}
	
	public static void main(String[] args) {
		// Test Linear-Search with various arrays and elements.
		int[] A = {31, 41, 59, 26, 41, 58};
		int nu = 31;
		testLinearSearch(A, nu);
		
		nu = 32;
		testLinearSearch(A, nu);
		
		int[] B = {1, 4, 39, 99, 100, 20};
		nu = 39;
		testLinearSearch(B, nu);
		
		nu = 101;
		testLinearSearch(B, nu);
	}
}
