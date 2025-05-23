#include <cmath>
#include <complex>

#include "square_matrix.h"

namespace clrs {
template <typename T>
square_matrix<T>::square_matrix(uint8_t n) : matrix<T>(n, n) {}

template <typename T>
square_matrix<T>::square_matrix(const matrix<T> &src) : matrix<T>(src) {}

template <typename T>
square_matrix<T>::square_matrix(const square_matrix<T> &src) : matrix<T>(src) {}

template <typename T>
square_matrix<T>::square_matrix(
    const std::initializer_list<std::initializer_list<T>> &src)
    : matrix<T>(src) {}

template <typename T> square_matrix<T>::~square_matrix() {}

template <typename T>
square_matrix<T> &square_matrix<T>::operator=(
    const std::initializer_list<std::initializer_list<T>> &src) {
  matrix<T>::operator=(src);
  return *this;
}

template <typename T>
square_matrix<T> &square_matrix<T>::operator=(const square_matrix<T> &src) {
  matrix<T>::operator=(src);
  return *this;
}

template <typename T>
square_matrix<T>
square_matrix<T>::operator+(const square_matrix<T> &src) const {
  uint8_t n = matrix<T>::m_rows;
  matrix<T> result(n, n);
  result = matrix<T>::operator+(src);
  return square_matrix<T>(result);
}

template <typename T>
square_matrix<T>
square_matrix<T>::operator-(const square_matrix<T> &src) const {
  uint8_t n = matrix<T>::m_rows;
  matrix<T> result(n, n);
  result = matrix<T>::operator-(src);
  return square_matrix<T>(result);
}

template <typename T>
square_matrix<T>
square_matrix<T>::operator*(const square_matrix<T> &src) const {
  if (std::floor(std::log2(matrix<T>::m_rows)) == std::log2(matrix<T>::m_rows))
    return square_matrix_multiply_recursive(src);
  else
    return square_matrix_multiply(src);
}

template <typename T>
square_matrix<T> square_matrix<T>::operator()(uint8_t m, uint8_t n) const {
  if (std::floor(std::log2(matrix<T>::m_rows)) ==
      std::log2(matrix<T>::m_rows)) {
    uint8_t new_rows = matrix<T>::m_rows / 2, new_cols = matrix<T>::m_cols / 2,
            p = 0;
    square_matrix<T> result(new_rows);

    for (uint8_t i = m * new_cols; i < (m + 1) * new_rows; i++) {
      uint8_t q = 0;
      for (uint8_t j = n * new_cols; j < (n + 1) * new_cols; j++) {
        result.m_data[p][q] = matrix<T>::m_data[i][j];
        q++;
      }
      p++;
    }

    return result;
  } else {
    throw new matrix_exception("Invalid dimensions, matrix must have "
                               "dimensions which are a power of 2");
  }
}

template <typename T>
square_matrix<T>
square_matrix<T>::square_matrix_multiply(const square_matrix<T> &src) const {
  uint8_t n = matrix<T>::m_rows;
  square_matrix<T> result(n);

  for (uint8_t i = 0; i < n; i++) {
    for (uint8_t j = 0; j < n; j++) {
      result.m_data[i][j] = 0;

      for (uint8_t k = 0; k < n; k++)
        result.m_data[i][j] =
            result.m_data[i][j] + matrix<T>::m_data[i][k] * src.m_data[k][j];
    }
  }

  return result;
}

template <typename T>
square_matrix<T> square_matrix<T>::square_matrix_multiply_recursive(
    const square_matrix<T> &src) const {
  uint8_t n = matrix<T>::m_rows;
  square_matrix<T> result(n);

  if (n > 1) {
    square_matrix<T> a11 = (*this)(0, 0);
    square_matrix<T> a12 = (*this)(0, 1);
    square_matrix<T> a21 = (*this)(1, 0);
    square_matrix<T> a22 = (*this)(1, 1);

    square_matrix<T> b11 = src(0, 0);
    square_matrix<T> b12 = src(0, 1);
    square_matrix<T> b21 = src(1, 0);
    square_matrix<T> b22 = src(1, 1);

    result.assign(0, 0,
                  (a11.square_matrix_multiply_recursive(b11)) +
                      (a12.square_matrix_multiply_recursive(b21)));
    result.assign(0, 1,
                  (a11.square_matrix_multiply_recursive(b12)) +
                      (a12.square_matrix_multiply_recursive(b22)));
    result.assign(1, 0,
                  (a21.square_matrix_multiply_recursive(b11)) +
                      (a22.square_matrix_multiply_recursive(b21)));
    result.assign(1, 1,
                  (a21.square_matrix_multiply_recursive(b12)) +
                      (a22.square_matrix_multiply_recursive(b22)));
  } else if (n == 1) {
    result.m_data[0][0] = matrix<T>::m_data[0][0] * src.m_data[0][0];
  }

  return result;
}

template <typename T>
void square_matrix<T>::assign(uint8_t m, uint8_t n,
                              const square_matrix<T> &src) {
  uint8_t new_rows = matrix<T>::m_rows / 2, new_cols = matrix<T>::m_cols / 2;

  for (uint8_t i = m * new_rows; i < (m + 1) * new_rows; i++) {
    for (uint8_t j = n * new_cols; j < (n + 1) * new_cols; j++) {
      if (i != 0 && j != 0) {
        matrix<T>::m_data[i][j] =
            src.m_data[(m * new_rows) % i][(n * new_cols) % j];
      } else {
        matrix<T>::m_data[i][j] = src.m_data[0][0];
      }
    }
  }
}

// See https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl for
// explanation
template class square_matrix<int>;
template class square_matrix<long>;
template class square_matrix<float>;
template class square_matrix<double>;
template class square_matrix<std::complex<int>>;
template class square_matrix<std::complex<long>>;
template class square_matrix<std::complex<float>>;
template class square_matrix<std::complex<double>>;
} // namespace clrs
