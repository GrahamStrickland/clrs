#include "max_subarray.h"

namespace clrs {
namespace algorithms {
namespace max_subarray {

// Brute-Force-Maximum-Subarray algorithm from ex. 4.1-2 p.74 of CLRS 3e
std::tuple<std::size_t, std::size_t, int>
brute_force_find_max_subarray(std::vector<int> a) {
  std::size_t max_low = 0, max_high = 0;
  int max_sum = a[0];

  for (std::size_t i = 0; i < a.size(); i++) {
    int current_sum = 0;
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

// Find-Maximum-Subarray algorithm from p.71-72 of CLRS 3e
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

// Non-recursive Find-Maximum-Subarray algorithm from ex. 4.1-5 on p.75 of CLRS
// 3e
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

// Combination of brute-force and divide-and-conquer Maximum-Subarray algorithms
// from ex. 4.1-3 p.74 of CLRS 3e
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
} // namespace max_subarray
} // namespace algorithms
} // namespace clrs
