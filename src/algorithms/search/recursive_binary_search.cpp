// Recursive-Binary-Search algorithm from ex. 2.3-5 from p.39 of CLRS 3e

#include <iostream>

int binarySearch(int A[], int nu, int low, int high);
void testBinarySearch(int A[], int len, int nu);

int main(int argc, char *argv[]) {
  int A[] = {26, 31, 41, 41, 58, 59};
  int len = 6;
  int nu = 31;
  testBinarySearch(A, len, nu);

  nu = 32;
  testBinarySearch(A, len, nu);

  int B[] = {1, 4, 5, 7, 19, 28, 45, 92};
  len = 8;
  nu = 7;
  testBinarySearch(B, len, nu);

  nu = 101;
  testBinarySearch(B, len, nu);

  return EXIT_SUCCESS;
}

int binarySearch(int A[], int nu, int low, int high) {
  if (low > high)
    return -1;
  int mid = low + (high - low) / 2;
  if (nu == A[mid])
    return mid;
  else if (nu > A[mid])
    return binarySearch(A, nu, mid + 1, high);
  else
    return binarySearch(A, nu, low, mid - 1);
}

void testBinarySearch(int A[], int len, int nu) {
  std::cout << "Array values: ";
  for (int i = 0; i < len; i++)
    std::cout << A[i] << ' ';
  std::cout << "\nnu = " << nu << '\n';

  std::cout << "Array does"
            << (binarySearch(A, nu, 0, len - 1) == -1 ? " not " : " ")
            << "contain " << nu << ".\n\n";
}
