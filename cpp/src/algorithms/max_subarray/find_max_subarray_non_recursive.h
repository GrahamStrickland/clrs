// Non-recursive Find-Maximum-Subarray algorithm from ex. 4.1-5 on p.75 of CLRS
// 3e

#ifndef FIND_MAX_SUBARRAY_NON_RECURSIVE_H
#define FIND_MAX_SUBARRAY_NON_RECURSIVE_H

#include <vector>

namespace clrs {
std::tuple<std::size_t, std::size_t, int>
find_maximum_subarray_non_recursive(std::vector<int> a, std::size_t low,
                                    std::size_t high) {
  int j = low + 1;
  std::tuple<std::size_t, std::size_t, int> max_subarray = {low, high,
                                                            a[low] + a[j]};
  int current_val = std::get<2>(max_subarray);

  while (j < static_cast<int>(high)) {
    current_val = a[j + 1];
    for (int i = j; i >= static_cast<int>(low); i--) {
      current_val += a[i];
      if (std::get<2>(max_subarray) < current_val) {
        std::get<0>(max_subarray) = i;
        std::get<1>(max_subarray) = j + 1;
        std::get<2>(max_subarray) = current_val;
      }
    }
    j++;
    current_val = std::get<2>(max_subarray);
  }

  return max_subarray;
}
} // namespace clrs
#endif // FIND_MAX_SUBARRAY_NON_RECURSIVE_H
