// Find-Maximum-Subarray algorithm from p.71-72 of CLRS 3e

#ifndef FIND_MAX_SUBARRAY_H
#define FIND_MAX_SUBARRAY_H

#include <vector>

namespace clrs {
std::tuple<std::size_t, std::size_t, int>
find_max_crossing_subarray(std::vector<int> a, std::size_t low, std::size_t mid,
                           std::size_t high) {
  int left_sum = INT_MIN, sum = 0;
  std::tuple<std::size_t, std::size_t, int> max_crossing_subarray = {low, high,
                                                                     sum};

  for (int i = static_cast<int>(mid); i >= static_cast<int>(low); i--) {
    sum = sum + a[static_cast<std::size_t>(i)];
    if (sum > left_sum) {
      left_sum = sum;
      std::get<0>(max_crossing_subarray) = static_cast<std::size_t>(i);
    }
  }

  int right_sum = INT_MIN;
  sum = 0;

  for (std::size_t j = mid + 1; j <= high; j++) {
    sum = sum + a[j];
    if (sum > right_sum) {
      right_sum = sum;
      std::get<1>(max_crossing_subarray) = j;
    }
  }

  std::get<2>(max_crossing_subarray) = left_sum + right_sum;

  return max_crossing_subarray;
}

std::tuple<std::size_t, std::size_t, int>
find_maximum_subarray(std::vector<int> a, std::size_t low, std::size_t high) {
  if (high == low) {
    return {low, high, a[low]};
  } else {
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
#endif // FIND_MAX_SUBARRAY_H
