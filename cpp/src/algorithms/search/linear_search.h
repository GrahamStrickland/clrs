// Linear-Search algorithm from ex2.1-3 p.22 of CLRS 3e

#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <span>

namespace clrs {
template <typename T, std::size_t N, typename V>
T linear_search(std::span<T, N> a, V const &nu) {
  uint8_t j = 0;

  while (j != a.size()) {
    if (a[j] == nu)
      return j;
    else
      j += 1;
  }

  return -1;
}
} // namespace clrs

#endif // LINEAR_SEARCH_H
