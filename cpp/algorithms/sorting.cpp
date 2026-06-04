#include <vector>

#include "sorting.h"

namespace clrs {
namespace algorithms {
namespace polynomials {
// Bubble-Sort algorithm from p.2-2 on pg. 40 of CLRS 3e
template <typename T, std::size_t N> void bubble_sort(std::array<T, N> &a) {
  auto len = a.size();
  for (std::size_t i = 0; i < len; i++) {
    for (std::size_t j = len - 1; j >= i + 1; j--) {
      if (a[j] < a[j - 1]) {
        int32_t temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
      }
    }
  }
}

// Count-Inversions algorithm from p. 2-4d on pg. 42 of CLRS 3e
template <typename T, std::size_t N>
std::size_t merge_inversions(std::array<T, N> &a, std::size_t p, std::size_t q,
                             std::size_t r) {
  std::size_t n1 = q - p + 1, n2 = r - q;

  std::vector<T> larr;
  larr.reserve(n1 + 1);
  std::vector<T> rarr;
  rarr.reserve(n2 + 1);

  for (std::size_t i = 0; i < n1; i++)
    larr[i] = a[p + i];
  for (std::size_t j = 0; j < n2; j++)
    rarr[j] = a[q + j + 1];

  larr[n1] = INT_MAX;
  rarr[n2] = INT_MAX;

  std::size_t i = 0, j = 0, inversions = 0;
  bool counted = false;

  for (std::size_t k = p; k <= r; k++) {
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
std::size_t count_inversions(std::array<T, N> &a, std::size_t p,
                             std::size_t r) {
  std::size_t inversions = 0;
  if (p < r) {
    std::size_t q = (p + r) / 2;
    inversions += count_inversions(a, p, q);
    inversions += count_inversions(a, q + 1, r);
    inversions += merge_inversions(a, p, q, r);
  }

  return inversions;
}

// Insertion-Sort algorithm from p. 18 of CLRS 3e
template <typename T, std::size_t N> void insertion_sort(std::array<T, N> &a) {
  auto len = a.size();
  for (std::size_t j = 1; j < len; j++) {
    T key = a[j];

    // Insert A[j] into the sorted sequence A[1..j-1]
    std::size_t i = j - 1;
    while (i >= 0 && a[i] > key) {
      T tmp = a[i + 1];
      a[i + 1] = a[i];
      a[i] = tmp;
      i--;
    }
    a[i + 1] = key;
  }
}

// Insertion-Sort algorithm in non-increasing order from ex2.1-2 on p.22 of CLRS
// 3e
template <typename T, std::size_t N>
void insertion_sort_reverse(std::array<T, N> &a) {
  for (std::size_t j = 1; j < a.size(); j++) {
    T key = a[j];

    // Insert A[j] into the sorted sequence A[1..j-1]
    auto i = j - 1;
    while (a[i] < key) {
      std::swap(a[i], a[i + 1]);
      i = i > 0 ? i - 1 : 0;
    }
  }
}

// Merge-Sort algorithm from p.31-34 of CLRS 3e
template <typename T, std::size_t N>
void merge(std::array<T, N> &a, std::size_t p, std::size_t q, std::size_t r) {
  std::size_t n1 = q - p + 1, n2 = r - q;

  std::vector<T> larr;
  larr.reserve(n1 + 1);
  std::vector<T> rarr;
  rarr.reserve(n2 + 1);

  for (std::size_t i = 0; i < n1; i++)
    larr[i] = a[p + i];
  for (std::size_t j = 0; j < n2; j++)
    rarr[j] = a[q + j + 1];

  larr[n1] = INT_MAX;
  rarr[n2] = INT_MAX;

  std::size_t i = 0, j = 0;

  for (std::size_t k = p; k <= r; k++) {
    if (larr[i] <= rarr[j]) {
      a[k] = larr[i];
      i++;
    } else {
      a[k] = rarr[j];
      j++;
    }
  }
}

template <typename T, std::size_t N>
void merge_sort(std::array<T, N> &a, std::size_t p, std::size_t r) {
  if (p < r) {
    std::size_t q = (p + r) / 2;
    merge_sort<T, N>(a, p, q);
    merge_sort<T, N>(a, q + 1, r);
    merge<T, N>(a, p, q, r);
  }
}

// Merge-Sort algorithm without sentinel values from ex. 2.3-2 p.37 of CLRS 3e
template <typename T, std::size_t N>
void merge_no_sentinel(std::array<T, N> &a, std::size_t p, std::size_t q,
                       std::size_t r) {
  std::size_t n1 = q - p + 1, n2 = r - q;

  std::vector<T> larr;
  larr.reserve(n1 + 1);
  std::vector<T> rarr;
  rarr.reserve(n2 + 1);

  for (std::size_t i = 0; i < n1; i++)
    larr[i] = a[p + i];
  for (std::size_t j = 0; j < n2; j++)
    rarr[j] = a[q + j + 1];

  std::size_t i = 0, j = 0;

  for (std::size_t k = p; k <= r; k++) {
    if (i < n1 && j < n2) {
      if (larr[i] <= rarr[j]) {
        a[k] = larr[i];
        i++;
      } else {
        a[k] = rarr[j];
        j++;
      }
    } else {
      if (i < n1) {
        a[k] = larr[i];
        i++;
      } else if (j < n2) {
        a[k] = rarr[j];
        j++;
      }
    }
  }
}

template <typename T, std::size_t N>
void merge_sort_no_sentinel(std::array<T, N> &a, std::size_t p, std::size_t r) {
  if (p < r) {
    uint8_t q = (p + r) / 2;
    merge_sort_no_sentinel<T, N>(a, p, q);
    merge_sort_no_sentinel<T, N>(a, q + 1, r);
    merge_no_sentinel<T, N>(a, p, q, r);
  }
}

// Selection-Sort algorithm from ex2.2-2 p.29 of CLRS 3e
template <typename T, std::size_t N> void selection_sort(std::array<T, N> &a) {
  std::size_t smallest;
  auto len = a.size();

  for (std::size_t i = 0; i < len - 1; i++) {
    smallest = i;

    for (std::size_t j = i + 1; j < len; j++)
      if (a[j] < a[smallest])
        smallest = j;

    T tmp = a[i];
    a[i] = a[smallest];
    a[smallest] = tmp;
  }
}

template void merge_sort<int, 8ul>(std::array<int, 8ul> &arr, unsigned long low,
                                   unsigned long high);
template void bubble_sort<int, 8ul>(std::array<int, 8ul> &arr);
template void insertion_sort<int, 8ul>(std::array<int, 8ul> &arr);
template void selection_sort<int, 8ul>(std::array<int, 8ul> &arr);
template void insertion_sort_reverse<int, 8ul>(std::array<int, 8ul> &arr);
template void merge_sort_no_sentinel<int, 8ul>(std::array<int, 8ul> &arr,
                                               unsigned long low,
                                               unsigned long high);
template unsigned long count_inversions<int, 5ul>(std::array<int, 5ul> &arr,
                                                  unsigned long low,
                                                  unsigned long high);
} // namespace polynomials
} // namespace algorithms
} // namespace clrs
