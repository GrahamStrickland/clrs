#ifndef POLYNOMIALS_H
#define POLYNOMIALS_H

#include <vector>

namespace clrs {
namespace algorithms {
namespace polynomials {
// Horners-Rule algorithm from p.2-3 on pg. 41 of CLRS 3e
double horners_rule(std::vector<double> coeffs, double x);
} // namespace polynomials
} // namespace algorithms
} // namespace clrs
#endif // POLYNOMIALS_H
