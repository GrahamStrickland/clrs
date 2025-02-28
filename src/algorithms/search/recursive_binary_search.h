// Recursive-Binary-Search algorithm from ex. 2.3-5 from p.39 of CLRS 3e

#ifndef RECURSIVE_BINARY_SEARCH_H
#define RECURSIVE_BINARY_SEARCH_H

#include <cstdint>

template <typename T>
T recursive_binary_search(T A[], T nu, uint8_t low, uint8_t high);

#endif // RECURSIVE_BINARY_SEARCH_H
