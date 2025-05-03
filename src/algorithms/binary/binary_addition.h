// Binary-Addition algorithm from ex. 2.1-4 of CLRS 3e

#ifndef BINARY_ADDITION_H
#define BINARY_ADDITION_H

#include <bitset>

namespace clrs {
template <std::size_t N>
std::bitset<N + 1> binary_addition(std::bitset<N> a, std::bitset<N> b) {
  std::bitset<N + 1> c;
  uint8_t carry = 0;
  size_t i;

  for (i = 0; i < N; i++) {

    if (a[i] == 1 && b[i] == 1) {
      if (carry == 0) {
        c[i] = 0;
      } else {
        c[i] = 1;
      }
      carry = 1;
    } else if ((a[i] == 1 && b[i] == 0) || (a[i] == 0 && b[i] == 1)) {
      if (carry == 0) {
        c[i] = 1;
      } else {
        c[i] = 0;
        carry = 1;
      }
    } else {
      c[i] = carry;
      carry = 0;
    }
  }

  c[i + 1] = carry;

  return c;
}
} // namespace clrs
#endif // BINARY_ADDITION_H
