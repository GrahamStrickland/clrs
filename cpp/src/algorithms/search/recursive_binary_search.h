// Recursive-Binary-Search algorithm from ex. 2.3-5 from p.39 of CLRS 3e

#ifndef RECURSIVE_BINARY_SEARCH_H
#define RECURSIVE_BINARY_SEARCH_H

#include <span>

namespace clrs {
template <typename T, std::size_t N, typename V>
T recursive_binary_search(std::span<T, N> a, V const &nu, uint8_t const &low,
                          uint8_t const &high) {
  if (low > high)
    return -1;
  uint8_t mid = low + (high - low) / 2;
  if (nu == a[mid])
    return mid;
  else if (nu > a[mid])
    return recursive_binary_search(a, nu, mid + 1, high);
  else
    return recursive_binary_search(a, nu, low, mid - 1);
}
} // namespace clrs

#endif // RECURSIVE_BINARY_SEARCH_H
