#include "linear_search.h"

int32_t linear_search(int32_t A[], uint8_t len, int32_t nu) {
  uint8_t j = 0;

  while (j != len) {
    if (A[j] == nu)
      return j;
    else
      j += 1;
  }

  return -1;
}

