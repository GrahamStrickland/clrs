// Binary-Addition algorithm from ex. 2.1-4 of CLRS 3e

#ifndef BINARY_ADDITION_H
#define BINARY_ADDITION_H

#include <bitset>

namespace clrs {
template <std::size_t N>
std::bitset<N + 1> binary_addition(std::bitset<N> a, std::bitset<N> b) {
  std::bitset<N + 1> c;
  uint8_t carry = 0b0;
  size_t i;

  for (i = 0; i < N; i++) {

    if (a[i] == 0b1 && b[i] == 0b1) {
      if (carry == 0b0) {
        c[i] = 0b0;
      } else {
        c[i] = 0b1;
      }
      carry = 0b1;
    } else if ((a[i] == 0b1 && b[i] == 0b0) || (a[i] == 0b0 && b[i] == 0b1)) {
      if (carry == 0b0) {
        c[i] = 0b1;
      } else {
        c[i] = 0b0;
        carry = 0b1;
      }
    } else {
      c[i] = carry;
      carry = 0b0;
    }
  }

  c[i] = carry;

  return c;
}
} // namespace clrs
#endif // BINARY_ADDITION_H
