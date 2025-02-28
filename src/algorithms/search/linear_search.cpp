#include "linear_search.h"

template <typename T> T linear_search(T A[], uint8_t len, T nu) {
  uint8_t j = 0;

  while (j != len) {
    if (A[j] == nu)
      return j;
    else
      j += 1;
  }

  return -1;
}
