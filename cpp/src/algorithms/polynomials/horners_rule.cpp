// Horners-Rule algorithm from p.2-3 on pg. 41 of CLRS 3e

#include <exception>
#include <iostream>
#include <string>

struct io_error : std::runtime_error {
  io_error(const std::string &message = "I/O error")
      : std::runtime_error(message) {}
};

double hornersRule(double coeffs[], int n, double x);
double *inputCoeffs(int &n);

int main(int argc, char *argv[]) {
  double x = 0.0;
  int len = 0;

  std::cout << "This is Horner's rule for evaluating a polynomial. ";

  double *coeffs = inputCoeffs(len);

  std::cout << "Please enter a value for x: ";
  try {
    std::cin >> x;
  } catch (io_error &e) {
    std::cout << "Cannot read input.";
  }

  std::cout << "For f(x) = " << coeffs[0];
  for (int i = 1; i <= len; i++)
    std::cout << (coeffs[i] > 0.0 ? " + " : " ") << "x"
              << (i > 1 ? "^" + std::to_string(i) : "");
  std::cout << ",\nResult: f(" << x << ") = " << hornersRule(coeffs, len, x)
            << '\n';

  return EXIT_SUCCESS;
}

double hornersRule(double coeffs[], int n, double x) {
  double y = 0;

  for (int i = n; i >= 0; i--)
    y = coeffs[i] + x * y;

  return y;
}

double *inputCoeffs(int &n) {
  double *coeffs;
  n = 0;

  std::cout << "Please input the degree of the polynomial (n): ";
  try {
    std::cin >> n;
  } catch (io_error) {
    std::cout << "Invalid Format!";
  }

  coeffs = new double[n];

  std::cout << "Please enter the coefficients in order a0, a1, ..., a" << n
            << ": \n";
  for (int coeff = 0; coeff <= n; coeff++) {
    try {
      std::cin >> coeffs[coeff];
    } catch (io_error) {
      std::cout << "Invalid Format!";
    }
  }

  return coeffs;
}
