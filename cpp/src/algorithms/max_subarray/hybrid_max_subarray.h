// Combination of brute-force and divide-and-conquer Maximum-Subarray algorithms
// from ex. 4.1-3 p.74 of CLRS 3e

#ifndef HYBRID_MAX_SUBARRAY_H
#define HYBRID_MAX_SUBARRAY_H

#include "brute_force_max_subarray.h"
#include "find_max_subarray.h"

#include <vector>

namespace clrs {
std::tuple<std::size_t, std::size_t, int>
hybrid_maximum_subarray(std::vector<int> a, std::size_t low, std::size_t high) {
  std::tuple<std::size_t, std::size_t, int> maximum_subarray = {low, high,
                                                                a[low]};

  if (high == low) {
    return maximum_subarray;    // Base case: only one element
  } else if (high - low < 20) { // For n_0 < 20, use faster brute-force approach
    return brute_force_find_max_subarray(a);
  } else { // Recursive algorithm for n_0 >= 20.
    std::size_t mid = (low + high) / 2;

    auto left_subarray = find_maximum_subarray(a, low, mid);
    auto right_subarray = find_maximum_subarray(a, mid + 1, high);
    auto cross_subarray = find_max_crossing_subarray(a, low, mid, high);

    if (std::get<2>(left_subarray) >= std::get<2>(right_subarray) &&
        std::get<2>(left_subarray) >= std::get<2>(cross_subarray)) {
      return left_subarray;
    } else if (std::get<2>(right_subarray) >= std::get<2>(left_subarray) &&
               std::get<2>(right_subarray) >= std::get<2>(cross_subarray)) {
      return right_subarray;
    } else {
      return cross_subarray;
    }
  }
}
} // namespace clrs
#endif // HYBRID_MAX_SUBARRAY_H
