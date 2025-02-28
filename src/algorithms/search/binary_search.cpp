#include "binary_search.h"

template <typename T> T binary_search(T A[], uint8_t len, T nu) {
  uint8_t low = 0;
  uint8_t high = len - 1;

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
