// Binary-Search algorithm from ex. 2.3-5 from p.39 of CLRS 3e

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <span>

namespace clrs {
template <typename T, std::size_t N, typename V>
T binary_search(std::span<T, N> a, V const &nu) {
  std::size_t low = 0;
  std::size_t high = a.size() - 1;

  while (low <= high) {
    std::size_t mid = low + (high - low) / 2;

    if (nu == a[mid])
      return mid;
    else if (nu > a[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}
} // namespace clrs
#endif // BINARY_SEARCH_H
