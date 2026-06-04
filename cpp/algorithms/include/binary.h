#ifndef BINARY_ADDITION_H
#define BINARY_ADDITION_H

#include <bitset>

namespace clrs {
namespace algorithms {
namespace binary {
template <std::size_t N>
// Binary-Addition algorithm from ex. 2.1-4 of CLRS 3e
std::bitset<N + 1> binary_addition(std::bitset<N> a, std::bitset<N> b);
} // namespace binary
} // namespace algorithms
} // namespace clrs
#endif // BINARY_ADDITION_H
