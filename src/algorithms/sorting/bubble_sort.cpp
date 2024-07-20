#include "bubble_sort.h"

void bubble_sort(int32_t A[], uint8_t len) {
  for (uint8_t i = 0; i < len; i++) {
    for (uint8_t j = len - 1; j >= i + 1; j--) {
      if (A[j] < A[j - 1]) {
        int32_t temp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = temp;
      }
    }
  }
}

