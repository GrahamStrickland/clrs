#ifndef SORTING_H
#define SORTING_H

#include <array>

namespace clrs {
namespace algorithms {
namespace sorting {
// Bubble-Sort algorithm from p.2-2 on pg. 40 of CLRS 3e
template <typename T, std::size_t N> void bubble_sort(std::array<T, N> &a);

// Count-Inversions algorithm from p. 2-4d on pg. 42 of CLRS 3e
template <typename T, std::size_t N>
std::size_t count_inversions(std::array<T, N> &a, std::size_t p, std::size_t r);

// Insertion-Sort algorithm from p. 18 of CLRS 3e
template <typename T, std::size_t N> void insertion_sort(std::array<T, N> &a);

// Insertion-Sort algorithm in non-increasing order from ex2.1-2 on p.22 of CLRS
// 3e
template <typename T, std::size_t N>
void insertion_sort_reverse(std::array<T, N> &a);

// Merge-Sort algorithm from p.31-34 of CLRS 3e
template <typename T, std::size_t N>
void merge_sort(std::array<T, N> &a, std::size_t p, std::size_t r);

// Merge-Sort algorithm without sentinel values from ex. 2.3-2 p.37 of CLRS 3e
template <typename T, std::size_t N>
void merge_sort_no_sentinel(std::array<T, N> &a, std::size_t p, std::size_t r);

// Selection-Sort algorithm from ex2.2-2 p.29 of CLRS 3e
template <typename T, std::size_t N> void selection_sort(std::array<T, N> &a);
} // namespace sorting
} // namespace algorithms
} // namespace clrs
#endif // SORTING_H
