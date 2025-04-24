// Bubble-Sort algorithm from p.2-2 on pg. 40 of CLRS 3e

#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <array>

namespace clrs {
template <typename T, std::size_t N> void bubble_sort(std::array<T, N> a) {
  auto len = a.size();
  for (uint8_t i = 0; i < len; i++) {
    for (uint8_t j = len - 1; j >= i + 1; j--) {
      if (a[j] < a[j - 1]) {
        int32_t temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
      }
    }
  }
}
} // namespace clrs
#endif // BUBBLE_SORT_H
