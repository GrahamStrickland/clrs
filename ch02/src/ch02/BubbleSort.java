// Bubble-Sort algorithm from p.2-2 on pg. 40 of CLRS 3e

package ch02;

public class BubbleSort {
	
	public static void bubbleSort(int[] A) {
		for (int i = 0; i < A.length; i++) {
			for (int j = A.length - 1; j >= i + 1; j--) {
				if (A[j] < A[j-1]) {
					int temp = A[j];
					A[j] = A[j-1];
					A[j-1] = temp;
				}
			}
		}
	}
	
	public static void testBubbleSort(int[] A) {
		// Print array before and after Bubble-Sort algorithm.
		System.out.println("Array before Bubble-Sort: ");
		for (int i : A) {
			System.out.print(i);
			System.out.print(' ');
		}
		
		bubbleSort(A);
		
		System.out.println("\n\nArray after Bubble-Sort: ");
		for (int i : A) {
			System.out.print(i);
			System.out.print(' ');
		}
		System.out.print("\n\n");
	}
	
	public static void main(String[] args) {
		// Test Bubble-Sort algorithm with various arrays.
		int[] A = {5, 2, 4, 6, 1, 3};
		testBubbleSort(A);
		
		int[] B = {31, 41, 59, 26, 41, 58};
		testBubbleSort(B);
		
		int[] C = {6, 5, 4, 3, 2, 1};
		testBubbleSort(C);
		
		int[] D = {5, 2, 4, 7, 1, 3, 2, 6};
		testBubbleSort(D);
		
		int[] E = {3, 41, 52, 26, 38, 57, 9, 49};
		testBubbleSort(E);
	}
}
