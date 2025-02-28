#include "insertion_sort.h"

template <typename T> void insertion_sort(T A[], uint8_t len) {
  for (uint8_t j = 1; j < len; j++) {
    T key = A[j];

    // Insert A[j] into the sorted sequence A[1..j-1]
    uint8_t i = j - 1;
    while (i >= 0 && A[i] > key) {
      A[i + 1] = A[i];
      i = i - 1;
    }
    A[i + 1] = key;
  }
}
