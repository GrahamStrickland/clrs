// Count-Inversions algorithm from p. 2-4d on pg. 42 of CLRS 3e

#include <iostream>

int mergeInversions(int A[], int p, int q, int r);
int countInversions(int A[], int p, int r);
void testCountInversions(int A[], int len);

int main(int argc, char *argv[]) {
  int A[] = {2, 3, 8, 6, 1};
  int B[] = {31, 41, 59, 26, 41, 58};
  int C[] = {6, 5, 4, 3, 2, 1};
  int D[] = {5, 2, 4, 7, 1, 3, 2, 6};
  int E[] = {3, 41, 52, 26, 38, 57, 9, 49};

  int len = 5;
  testCountInversions(A, len);

  len = 6;
  testCountInversions(B, len);

  len = 6;
  testCountInversions(C, len);

  len = 8;
  testCountInversions(D, len);

  testCountInversions(E, len);

  return EXIT_SUCCESS;
}

int mergeInversions(int A[], int p, int q, int r) {
  int n1 = q - p + 1, n2 = r - q;

  int L[n1 + 1], R[n2 + 1];

  for (int i = 0; i < n1; i++)
    L[i] = A[p + i];
  for (int j = 0; j < n2; j++)
    R[j] = A[q + j + 1];

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  int i = 0, j = 0, inversions = 0;
  bool counted = false;

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

int countInversions(int A[], int p, int r) {
  int inversions = 0;
  if (p < r) {
    int q = (p + r) / 2;
    inversions += countInversions(A, p, q);
    inversions += countInversions(A, q + 1, r);
    inversions += mergeInversions(A, p, q, r);
  }

  return inversions;
}

void testCountInversions(int A[], int len) {
  std::cout << "Array: ";
  for (int i = 0; i < len; i++)
    std::cout << A[i] << ' ';
  std::cout << '\n';

  std::cout << "\nNumber of inversions: " << countInversions(A, 0, len - 1)
            << '\n';
}
