// Merge-Sort algorithm without sentinel values from ex. 2.3-2 p.37 of CLRS 3e
package section2_3;

public class MergeSortNoSentinel {
	
	// Merge procedure to merge two sorted arrays.
	public static void merge(int[] A, int p, int q, int r) {
		int n1 = q - p + 1, n2 = r - q;
		
		int[] L, R;
		L = new int[n1];
		R = new int[n2];
		
		for (int i = 0; i < n1; i++)
			L[i] = A[p+i];
		for (int j = 0; j < n2; j++)
			R[j] = A[q+j+1];
		
		int i = 0, j = 0;
		
		for (int k = p; k <= r; k++) {
			if (i < n1 && j < n2) {
				if (L[i] <= R[j]) {
					A[k] = L[i];
					i++;
				} else {
					A[k] = R[j];
					j++;
				}
			} else {
				if (i < n1) {
					A[k] = L[i];
					i++;
				} else if (j < n2) {
					A[k] = R[j];
					j++;
				}
			}
		}
	}
	
	// Merge-Sort procedure to recursively merge subarrays.
	public static void mergeSort(int[] A, int p, int r) {
		if (p < r) {
			int q = (p + r) / 2;
			mergeSort(A, p, q);
			mergeSort(A, q+1, r);
			merge(A, p, q, r);
		}
	}
	
	public static void testMergeSort(int[] A) {
		// Print array before and after Merge-Sort algorithm.
		System.out.println("Array before Merge-Sort: ");
		for (int i : A) {
			System.out.print(i);
			System.out.print(' ');
		}
		
		mergeSort(A, 0, A.length-1);
		
		System.out.println("\n\nArray after Merge-Sort: ");
		for (int i : A) {
			System.out.print(i);
			System.out.print(' ');
		}
		System.out.print("\n\n");
	}
	
	public static void main(String[] args) {
		// Test Merge-Sort algorithm with various arrays.
		int[] A = {5, 2, 4, 6, 1, 3};
		testMergeSort(A);
		
		int[] B = {31, 41, 59, 26, 41, 58};
		testMergeSort(B);
		
		int[] C = {6, 5, 4, 3, 2, 1};
		testMergeSort(C);
		
		int[] D = {5, 2, 4, 7, 1, 3, 2, 6};
		testMergeSort(D);
		
		int[] E = {3, 41, 52, 26, 38, 57, 9, 49};
		testMergeSort(E);
	}
}
