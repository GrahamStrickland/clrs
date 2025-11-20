// Insertion-Sort algorithm in non-increasing order from ex2.1-2 on p.22 of CLRS
// 3e

#ifndef INSERTION_SORT_REVERSE_H
#define INSERTION_SORT_REVERSE_H

#include <array>

namespace clrs {
template <typename T, std::size_t N>
void insertion_sort_reverse(std::array<T, N> &a) {
  for (std::size_t j = 1; j < a.size(); j++) {
    T key = a[j];

    // Insert A[j] into the sorted sequence A[1..j-1]
    auto i = j - 1;
    while (a[i] < key) {
      std::swap(a[i], a[i + 1]);
      i = i > 0 ? i - 1 : 0; 
    }
  }
}
} // namespace clrs
#endif // INSERTION_SORT_REVERSE_H
