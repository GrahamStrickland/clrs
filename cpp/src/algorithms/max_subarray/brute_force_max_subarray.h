// Brute-Force-Maximum-Subarray algorithm from ex. 4.1-2 p.74 of CLRS 3e

#ifndef BRUTE_FORCE_MAX_SUBARRAY_H
#define BRUTE_FORCE_MAX_SUBARRAY_H

#include <span>

namespace clrs {
template <typename T, std::size_t N>
std::tuple<std::size_t, std::size_t, T>
brute_force_find_max_subarray(std::span<T, N> a) {
  std::size_t low = 0, high = 1;
  T sum = 0;
  std::tuple<std::size_t, std::size_t, T> max_subarray = {low, high, sum};

  while (low < a.size() - 2) {
    while (high < a.size() - 1) {
      sum += a[high];
      if (sum > std::get<2>(max_subarray)) {
        std::get<0>(max_subarray) = low;
        std::get<1>(max_subarray) = high;
        std::get<2>(max_subarray) = sum;
      }
      high++;
    }
    low++;
    high = low + 1;
    sum = 0;
  }

  return max_subarray;
}
} // namespace clrs
#endif // BRUTE_FORCE_MAX_SUBARRAY_H
