// Count-Inversions algorithm from p. 2-4d on pg. 42 of CLRS 3e
package problems;

public class CountInversions {
	
	// Merge procedure to merge two sorted arrays and count inversions.
	public static int mergeInversions(int[] A, int p, int q, int r) {
		int n1 = q - p + 1, n2 = r - q;
		
		int[] L, R;
		L = new int[n1+1];
		R = new int[n2+1];
		
		for (int i = 0; i < n1; i++)
			L[i] = A[p+i];
		for (int j = 0; j < n2; j++)
			R[j] = A[q+j+1];
		
		L[n1] = Integer.MAX_VALUE;
		R[n2] = Integer.MAX_VALUE;
		
		int i = 0, j = 0, inversions = 0;
		Boolean counted = false;
		
		for (int k = p; k <= r; k++) {
			if (!counted && R[j] < L[i]) {
				inversions += n1 - i;
				counted = true;
			}
			if (L[i] <= R[j]) {
				A[k] = L[i];
				i++;
			} else {
				A[k] = R[j];
				j++;
				counted = false;
			}
		}
		return inversions;
	}
	
	// Merge-Sort procedure to recursively merge subarrays and count inversions.
	public static int countInversions(int[] A, int p, int r) {
		int inversions = 0;
		if (p < r) {
			int q = (p + r) / 2;
			inversions += countInversions(A, p, q);
			inversions += countInversions(A, q+1, r);
			inversions += mergeInversions(A, p, q, r);
		}
		return inversions;
	}
	
	public static void testCountInversions(int[] A) {
		// Print output of Count-Inversions algorithm.
		System.out.println("Array: ");
		for (int i : A) {
			System.out.print(i);
			System.out.print(' ');
		}
		
		System.out.println("\nNumber of inversions: " + countInversions(A, 0, A.length - 1));
		System.out.println();
	}
	
	public static void main(String[] args) {
		// Test Merge-Sort algorithm with various arrays.
		int[] A = {2, 3, 8, 6, 1};
		testCountInversions(A);
		
		int[] B = {31, 41, 59, 26, 41, 58};
		testCountInversions(B);
		
		int[] C = {6, 5, 4, 3, 2, 1};
		testCountInversions(C);
		
		int[] D = {5, 2, 4, 7, 1, 3, 2, 6};
		testCountInversions(D);
		
		int[] E = {3, 41, 52, 26, 38, 57, 9, 49};
		testCountInversions(E);
	}
}
