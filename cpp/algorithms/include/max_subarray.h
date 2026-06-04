#ifndef MAX_SUBARRAY_H
#define MAX_SUBARRAY_H

#include <vector>

namespace clrs {
namespace algorithms {
namespace max_subarray {
// Brute-Force-Maximum-Subarray algorithm from ex. 4.1-2 p.74 of CLRS 3e
std::tuple<std::size_t, std::size_t, int>
brute_force_find_max_subarray(std::vector<int> a);

// Find-Maximum-Subarray algorithm from p.71-72 of CLRS 3e
std::tuple<std::size_t, std::size_t, int>
find_maximum_subarray(std::vector<int> a, std::size_t low, std::size_t high);

// Non-recursive Find-Maximum-Subarray algorithm from ex. 4.1-5 on p.75 of CLRS
// 3e
std::tuple<std::size_t, std::size_t, int>
find_maximum_subarray_non_recursive(std::vector<int> a, std::size_t low,
                                    std::size_t high);

// Combination of brute-force and divide-and-conquer Maximum-Subarray algorithms
// from ex. 4.1-3 p.74 of CLRS 3e
std::tuple<std::size_t, std::size_t, int>
hybrid_maximum_subarray(std::vector<int> a, std::size_t low, std::size_t high);
} // namespace max_subarray
} // namespace algorithms
} // namespace clrs
#endif // MAX_SUBARRAY_H
