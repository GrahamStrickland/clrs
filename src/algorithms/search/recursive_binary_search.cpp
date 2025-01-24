#include "recursive_binary_search.h"

int32_t recursive_binary_search(int32_t A[], int32_t nu, uint8_t low, uint8_t high) {
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

