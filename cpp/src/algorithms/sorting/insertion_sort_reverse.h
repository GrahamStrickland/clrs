// Insertion-Sort algorithm in non-increasing order from ex2.1-2 on p.22 of CLRS
// 3e

#ifndef INSERTION_SORT_REVERSE_H
#define INSERTION_SORT_REVERSE_H

#include <array>

namespace clrs {
template <typename T, std::size_t N>
void insertion_sort_reverse(std::array<T, N> &a) {
  auto len = a.size();
  for (std::size_t j = 1; j < len; j++) {
    T key = a[j];

    // Insert A[j] into the sorted sequence A[1..j-1]
    std::size_t i = j - 1;
    while (i >= 0 && a[i] < key) {
      a[i + 1] = a[i];
      i = i - 1;
    }
    a[i + 1] = key;
  }
}
} // namespace clrs
#endif // INSERTION_SORT_REVERSE_H
