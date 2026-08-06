// Algorithms for Problem p1-1 from p.14 of CLRS 3e
#ifndef BIG_OH_H
#define BIG_OH_H

namespace clrs {
namespace algorithms {
namespace big_oh {
/**
 * Computes the inverse of `n log(n)`.
 *
 * @param `x` The value `x` such that `n log(n) = x`.
 */
double inverse_nlogn(double x);

/**
 * Computes the inverse of `n!`, i.e. the largest `n` such that `n! <= x`.
 *
 * @param `x` The value `x` such that `n! = x`.
 */
double inverse_factorial(double x);
} // namespace big_oh
} // namespace algorithms
} // namespace clrs
#endif // BIG_OH_H
