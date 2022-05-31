// Selection-Sort algorithm from ex2.2-2 p.29 of CLRS 3e

package ch02;

public class SelectionSort {
	public static void selectionSort(int[] A) {
		int n = A.length, smallest, temp;
		for (int j = 0; j < n-1; j++) {
			smallest = j;
			for (int i = j+1; i < n; i++) {
				if (A[i] < A[smallest])
					smallest = i;
			}
			temp = A[j];
			A[j] = A[smallest];
			A[smallest] = temp;
		}
	}
	
	public static void testSelectionSort(int[] A) {
		// Print array before and after Selection-Sort algorithm.
		System.out.println("Array before Selection-Sort: ");
		for (int i : A) {
			System.out.print(i);
			System.out.print(' ');
		}
		
		selectionSort(A);
		
		System.out.println("\n\nArray after Selection-Sort: ");
		for (int i : A) {
			System.out.print(i);
			System.out.print(' ');
		}
		System.out.print("\n\n");
	}
	
	public static void main(String[] args) {
		// Test Selection-Sort algorithm with various arrays.
		int[] A = {5, 2, 4, 6, 1, 3};
		testSelectionSort(A);
		
		int[] B = {31, 41, 59, 26, 41, 58};
		testSelectionSort(B);
		
		int[] C = {6, 5, 4, 3, 2, 1};
		testSelectionSort(C);
	}
}
