#ifndef SEARCH_H
#define SEARCH_H

#include <span>

namespace clrs {
namespace algorithms {
namespace search {
template <typename T, std::size_t N, typename V>
// Binary-Search algorithm from ex. 2.3-5 from p.39 of CLRS 3e
int binary_search(std::span<T, N> a, V const &nu);

// Linear-Search algorithm from ex2.1-3 p.22 of CLRS 3e
template <typename T, std::size_t N, typename V>
int linear_search(std::span<T, N> a, V const &nu);

// Recursive-Binary-Search algorithm from ex. 2.3-5 from p.39 of CLRS 3e
template <typename T, std::size_t N, typename V>
int recursive_binary_search(std::span<T, N> a, V const &nu,
                          std::size_t const &low, std::size_t const &high);
} // namespace search
} // namespace algorithms
} // namespace clrs
#endif // SEARCH_H
