// Binary-Search algorithm from ex. 2.3-5 from p.39 of CLRS 3e

#include <iostream>

int32_t binary_search(int32_t A[], uint8_t len, int32_t nu) {
  uint8_t low = 0, high = len - 1;

  while (low <= high) {
    uint8_t mid = low + (high - low) / 2;

    if (nu == A[mid])
      return mid;
    else if (nu > A[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}
