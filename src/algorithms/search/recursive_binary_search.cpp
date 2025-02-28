#include "recursive_binary_search.h"

template <typename T>
T recursive_binary_search(T A[], T nu, uint8_t low, uint8_t high) {
  if (low > high)
    return -1;
  uint8_t mid = low + (high - low) / 2;
  if (nu == A[mid])
    return mid;
  else if (nu > A[mid])
    return recursive_binary_search(A, nu, mid + 1, high);
  else
    return recursive_binary_search(A, nu, low, mid - 1);
}
