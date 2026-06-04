#include "search.h"

namespace clrs {
namespace algorithms {
namespace polynomials {
template <typename T, std::size_t N, typename V>
// Binary-Search algorithm from ex. 2.3-5 from p.39 of CLRS 3e
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

// Linear-Search algorithm from ex2.1-3 p.22 of CLRS 3e
template <typename T, std::size_t N, typename V>
T linear_search(std::span<T, N> a, V const &nu) {
  std::size_t j = 0;

  while (j != a.size()) {
    if (a[j] == nu)
      return j;
    else
      j += 1;
  }

  return -1;
}

// Recursive-Binary-Search algorithm from ex. 2.3-5 from p.39 of CLRS 3e
template <typename T, std::size_t N, typename V>
T recursive_binary_search(std::span<T, N> a, V const &nu,
                          std::size_t const &low, std::size_t const &high) {
  if (low > high)
    return -1;
  std::size_t mid = low + (high - low) / 2;
  if (nu == a[mid])
    return mid;
  else if (nu > a[mid])
    return recursive_binary_search(a, nu, mid + 1, high);
  else
    return recursive_binary_search(a, nu, low, mid - 1);
}

template int binary_search<int, 8ul, int>(std::span<int, 8ul> container,
                                          int const &target);
template int linear_search<int, 8ul, int>(std::span<int, 8ul> container,
                                          int const &target);
template int recursive_binary_search<int, 8ul, int>(
    std::span<int, 8ul> container, int const &target, unsigned long const &low,
    unsigned long const &high);
} // namespace polynomials
} // namespace algorithms
} // namespace clrs
