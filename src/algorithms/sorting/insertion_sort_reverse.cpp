// Insertion-Sort algorithm in non-increasing order from ex2.1-2 on p.22 of CLRS
// 3e

#include <iostream>

void testInsertionSort(int A[], int len);
void insertionSort(int A[], int len);

int main(int argc, char *argv[]) {
  // Test Insertion-Sort algorithm with various arrays
  int A[] = {5, 2, 4, 6, 1, 3};
  int B[] = {31, 41, 59, 26, 41, 58};
  int C[] = {6, 5, 4, 3, 2, 1};
  int len = 6;

  testInsertionSort(A, len);
  testInsertionSort(B, len);
  testInsertionSort(C, len);

  return EXIT_SUCCESS;
}

void testInsertionSort(int A[], int len) {
  // Print array before and after Insertion-Sort algorithm
  std::cout << "Array before Insertion-Sort: ";
  for (int i = 0; i < len; i++)
    std::cout << A[i] << ' ';

  insertionSort(A, len);

  std::cout << "\n\nArray after Insertion-Sort: ";
  for (int i = 0; i < len; i++)
    std::cout << A[i] << ' ';
  std::cout << "\n\n";
}

void insertionSort(int A[], int len) {
  for (int j = 1; j < len; j++) {
    int key = A[j];

    // Insert A[j] into the sorted sequence A[1..j-1]
    int i = j - 1;
    while (i >= 0 && A[i] < key) {
      A[i + 1] = A[i];
      i = i - 1;
    }
    A[i + 1] = key;
  }
}
