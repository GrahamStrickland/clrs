// Algorithms for Problem p1-1 from p.14 of CLRS 3e
#include <cmath>
#include <cstdlib>

#include "big_oh.h"

namespace clrs {
namespace algorithms {
namespace big_oh {
double inverse_nlogn(double x) {
  std::size_t max_iters = 10;
  double a_0 = x / std::log2(x), a_1 = 0.0;

  for (std::size_t i = 0; i < max_iters; ++i) {
    a_1 = a_0 - ((a_0 * std::log2(a_0) - x) /
                 ((1.0 / std::log(2.0)) + std::log2(a_0)));
    if (abs((a_1 * std::log2(a_1)) - (a_0 * std::log2(a_0))) < 1)
      return a_1;
    else
      a_0 = a_1;
  }

  return a_1;
}

double inverse_factorial(double x) {
  double i = 0, fact = 1;

  while (fact < x) {
    if (i > 0)
      fact *= i;
    i++;
  }

  return i - 1;
}
} // namespace big_oh
} // namespace algorithms
} // namespace clrs
