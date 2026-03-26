// Merge-Sort algorithm from p.31-34 of CLRS 3e

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <array>
#include <vector>

namespace clrs {

template <typename T, std::size_t N>
void merge(std::array<T, N> &a, std::size_t p, std::size_t q, std::size_t r) {
  std::size_t n1 = q - p + 1, n2 = r - q;

  std::vector<T> larr;
  larr.reserve(n1 + 1);
  std::vector<T> rarr;
  rarr.reserve(n2 + 1);

  for (std::size_t i = 0; i < n1; i++)
    larr[i] = a[p + i];
  for (std::size_t j = 0; j < n2; j++)
    rarr[j] = a[q + j + 1];

  larr[n1] = INT_MAX;
  rarr[n2] = INT_MAX;

  std::size_t i = 0, j = 0;

  for (std::size_t k = p; k <= r; k++) {
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
void merge_sort(std::array<T, N> &a, std::size_t p, std::size_t r) {
  if (p < r) {
    std::size_t q = (p + r) / 2;
    merge_sort<T, N>(a, p, q);
    merge_sort<T, N>(a, q + 1, r);
    merge<T, N>(a, p, q, r);
  }
}
} // namespace clrs
#endif // MERGE_SORT_H
