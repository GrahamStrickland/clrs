// Selection-Sort algorithm from ex2.2-2 p.29 of CLRS 3e

#include <iostream>

void testSelectionSort(int A[], int len);
void selectionSort(int A[], int len);

int main(int argc, char *argv[]) {
  int A[] = {5, 2, 4, 6, 1, 3};
  int B[] = {31, 41, 59, 26, 41, 58};
  int C[] = {6, 5, 4, 3, 2, 1};
  int len = 6;

  testSelectionSort(A, len);
  testSelectionSort(B, len);
  testSelectionSort(C, len);

  return EXIT_SUCCESS;
}

void testSelectionSort(int A[], int len) {
  std::cout << "Array before Selection-Sort: ";
  for (int i = 0; i < len; i++)
    std::cout << A[i] << ' ';

  selectionSort(A, len);

  std::cout << "\n\nArray after Selection-Sort: ";
  for (int i = 0; i < len; i++)
    std::cout << A[i] << ' ';
  std::cout << "\n\n";
}

void selectionSort(int A[], int len) {
  int smallest, temp;

  for (int j = 0; j < len - 1; j++) {
    smallest = j;

    for (int i = j + 1; i < len; i++)
      if (A[i] < A[smallest])
        smallest = i;

    temp = A[j];
    A[j] = A[smallest];
    A[smallest] = temp;
  }
}
