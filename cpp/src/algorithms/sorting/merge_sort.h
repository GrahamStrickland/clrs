// Merge-Sort algorithm from p.31-34 of CLRS 3e

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <array>
#include <vector>

namespace clrs {

template <typename T, std::size_t N>
void merge(std::array<T, N> &a, uint8_t p, uint8_t q, uint8_t r) {
  uint8_t n1 = q - p + 1, n2 = r - q;

  std::vector<T> larr;
  larr.reserve(n1 + 1);
  std::vector<T> rarr;
  rarr.reserve(n2 + 1);

  for (uint8_t i = 0; i < n1; i++)
    larr[i] = a[p + i];
  for (uint8_t j = 0; j < n2; j++)
    rarr[j] = a[q + j + 1];

  larr[n1] = INT_MAX;
  rarr[n2] = INT_MAX;

  uint8_t i = 0, j = 0;

  for (uint8_t k = p; k <= r; k++) {
    if (larr[i] <= rarr[j]) {
      a[k] = larr[i];
      i++;
    } else {
      a[k] = rarr[j];
      j++;
    }
  }
}

template <typename T, std::size_t N>
void merge_sort(std::array<T, N> &a, uint8_t p, uint8_t r) {
  if (p < r) {
    uint8_t q = (p + r) / 2;
    merge_sort<T, N>(a, p, q);
    merge_sort<T, N>(a, q + 1, r);
    merge<T, N>(a, p, q, r);
  }
}
} // namespace clrs
#endif // MERGE_SORT_H
