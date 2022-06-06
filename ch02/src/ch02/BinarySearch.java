// Binary-Search algorithm from ex. 2.3-5 from p.39 of CLRS 3e

package ch02;

public class BinarySearch {
	
	public static int binarySearch(int[] A, int nu) {
		int low = 1, high = A.length - 1;
		
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (A[mid] < nu)
				low = mid + 1;
			else if (A[mid] == nu)
				return mid;
			else
				high = mid - 1;
		}
		return -1;
	}
	
	public static void testBinarySearch(int[] A, int nu) {
		// Test Binary-Search algorithm with array A.
		System.out.print("Array values: ");
		
		for (int i : A) {
			System.out.print(i);
			System.out.print(' ');
		}
		System.out.format("\nnu = %d\n", nu);
		
		System.out.format("Array does"+(binarySearch(A, nu)==-1?" not ":" ")+"contain %d.\n\n", nu);
	}
	
	public static void main(String[] args) {
		// Test Binary-Search with various arrays and elements.
		int[] A = {26, 31, 41, 41, 58, 59};
		int nu = 31;
		testBinarySearch(A, nu);
		
		nu = 32;
		testBinarySearch(A, nu);
		
		int[] B = {1, 4, 5, 7, 19, 28, 45, 92};
		nu = 7;
		testBinarySearch(B, nu);
		
		nu = 101;
		testBinarySearch(B, nu);
	}
}
