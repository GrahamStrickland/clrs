// Brute-Force-Maximum-Subarray algorithm from ex. 4.1-2 p.74 of CLRS 3e

#ifndef BRUTE_FORCE_MAX_SUBARRAY_H
#define BRUTE_FORCE_MAX_SUBARRAY_H

#include <span>

namespace clrs {
template <typename T, std::size_t N>
std::tuple<std::size_t, std::size_t, T>
brute_force_find_max_subarray(std::span<T, N> a) {
  std::size_t max_low = 0, max_high = 0;
  T max_sum = a[0];

  for (std::size_t i = 0; i < a.size(); i++) {
    T current_sum = 0;
    for (std::size_t j = i; j < a.size(); j++) {
      current_sum += a[j];
      if (current_sum > max_sum) {
        max_sum = current_sum;
        max_low = i;
        max_high = j;
      }
    }
  }

  return {max_low, max_high, max_sum};
}
} // namespace clrs
#endif // BRUTE_FORCE_MAX_SUBARRAY_H
