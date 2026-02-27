// Merge-Sort algorithm without sentinel values from ex. 2.3-2 p.37 of CLRS 3e

#ifndef MERGE_SORT_NO_SENTINEL_H
#define MERGE_SORT_NO_SENTINEL_H

#include <array>
#include <vector>

namespace clrs {

template <typename T, std::size_t N>
void merge_no_sentinel(std::array<T, N> &a, uint8_t p, uint8_t q, uint8_t r) {
  uint8_t n1 = q - p + 1, n2 = r - q;

  std::vector<T> larr;
  larr.reserve(n1 + 1);
  std::vector<T> rarr;
  rarr.reserve(n2 + 1);

  for (uint8_t i = 0; i < n1; i++)
    larr[i] = a[p + i];
  for (uint8_t j = 0; j < n2; j++)
    rarr[j] = a[q + j + 1];

  uint8_t i = 0, j = 0;

  for (uint8_t k = p; k <= r; k++) {
    if (i < n1 && j < n2) {
      if (larr[i] <= rarr[j]) {
        a[k] = larr[i];
        i++;
      } else {
        a[k] = rarr[j];
        j++;
      }
    } else {
      if (i < n1) {
        a[k] = larr[i];
        i++;
      } else if (j < n2) {
        a[k] = rarr[j];
        j++;
      }
    }
  }
}

template <typename T, std::size_t N>
void merge_sort_no_sentinel(std::array<T, N> &a, uint8_t p, uint8_t r) {
  if (p < r) {
    uint8_t q = (p + r) / 2;
    merge_sort_no_sentinel<T, N>(a, p, q);
    merge_sort_no_sentinel<T, N>(a, q + 1, r);
    merge_no_sentinel<T, N>(a, p, q, r);
  }
}
} // namespace clrs
#endif // MERGE_SORT_NO_SENTINEL_H
