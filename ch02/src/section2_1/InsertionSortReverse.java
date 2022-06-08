// Insertion-Sort algorithm in non-increasing order from ex2.1-2 on p.22 of CLRS 3e

package section2_1;

public class InsertionSortReverse {
	public static void insertionSort(int[] A) {
		for (int j = 1; j < A.length; j++) {
			int key = A[j];
			// Insert A[j] into the sorted sequence A[1..j-1].
			int i = j - 1;
			while (i >= 0 && A[i] < key) {
				A[i+1] = A[i];
				i = i - 1;
			}
			A[i+1] = key;
		}
	}
	
	public static void testInsertionSort(int[] A) {
		// Print array before and after Insertion-Sort algorithm.
		System.out.println("Array before Insertion-Sort: ");
		for (int i : A) {
			System.out.print(i);
			System.out.print(' ');
		}
		
		insertionSort(A);
		
		System.out.println("\n\nArray after Insertion-Sort: ");
		for (int i : A) {
			System.out.print(i);
			System.out.print(' ');
		}
		System.out.print("\n\n");
	}
	
	public static void main(String[] args) {
		// Test Insertion-Sort algorithm with various arrays.
		int[] A = {5, 2, 4, 6, 1, 3};
		testInsertionSort(A);
		
		int[] B = {31, 41, 59, 26, 41, 58};
		testInsertionSort(B);
		
		int[] C = {6, 5, 4, 3, 2, 1};
		testInsertionSort(C);
	}
}
