// Count-Inversions algorithm from p. 2-4d on pg. 42 of CLRS 3e

#ifndef COUNT_INVERSIONS_H
#define COUNT_INVERSIONS_H

#include <array>
#include <vector>

namespace clrs {

template <typename T, std::size_t N>
int merge_inversions(std::array<T, N> &a, uint8_t p, uint8_t q, uint8_t r) {
  uint8_t n1 = q - p + 1, n2 = r - q;

  std::vector<T> larr;
  larr.reserve(n1 + 1);
  std::vector<T> rarr;
  rarr.reserve(n2 + 1);

  for (int i = 0; i < n1; i++)
    larr[i] = a[p + i];
  for (int j = 0; j < n2; j++)
    rarr[j] = a[q + j + 1];

  larr[n1] = INT_MAX;
  rarr[n2] = INT_MAX;

  int i = 0, j = 0, inversions = 0;
  bool counted = false;

  for (int k = p; k <= r; k++) {
    if (!counted && rarr[j] < larr[i]) {
      inversions += n1 - i;
      counted = true;
    }
    if (larr[i] <= rarr[j]) {
      a[k] = larr[i];
      i++;
    } else {
      a[k] = rarr[j];
      j++;
      counted = false;
    }
  }

  return inversions;
}

template <typename T, std::size_t N>
std::size_t count_inversions(std::array<T, N> &a, uint8_t p, uint8_t r) {
  std::size_t inversions = 0;
  if (p < r) {
    uint8_t q = (p + r) / 2;
    inversions += count_inversions(a, p, q);
    inversions += count_inversions(a, q + 1, r);
    inversions += merge_inversions(a, p, q, r);
  }

  return inversions;
}
} // namespace clrs
#endif // COUNT_INVERSIONS_H
