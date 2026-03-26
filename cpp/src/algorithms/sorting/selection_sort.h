// Selection-Sort algorithm from ex2.2-2 p.29 of CLRS 3e

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <array>

namespace clrs {
template <typename T, std::size_t N> void selection_sort(std::array<T, N> &a) {
  std::size_t smallest;
  auto len = a.size();

  for (std::size_t i = 0; i < len - 1; i++) {
    smallest = i;

    for (std::size_t j = i + 1; j < len; j++)
      if (a[j] < a[smallest])
        smallest = j;

    T tmp = a[i];
    a[i] = a[smallest];
    a[smallest] = tmp;
  }
}
} // namespace clrs

#endif // SELECTION_SORT_H
