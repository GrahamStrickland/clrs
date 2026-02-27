// Horners-Rule algorithm from p.2-3 on pg. 41 of CLRS 3e

#ifndef HORNERS_RULE_H
#define HORNERS_RULE_H

#include <vector>

namespace clrs {
double horners_rule(std::vector<double> coeffs, double x) {
  double y = 0;

  for (int i = static_cast<int>(coeffs.size()) - 1; i >= 0; i--)
    y = coeffs[i] + x * y;

  return y;
}
} // namespace clrs
#endif // HORNERS_RULE_H
