#include <cassert>
#include <cmath>
#include <complex>

#include "square_matrix.h"

namespace clrs {
template <typename T>
square_matrix<T>::square_matrix(std::size_t n) : matrix<T>(n, n) {}

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
  std::size_t n = matrix<T>::m_rows;
  matrix<T> result(n, n);
  result = matrix<T>::operator+(src);
  return square_matrix<T>(result);
}

template <typename T>
square_matrix<T>
square_matrix<T>::operator-(const square_matrix<T> &src) const {
  std::size_t n = matrix<T>::m_rows;
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
square_matrix<T> square_matrix<T>::operator()(std::size_t m,
                                              std::size_t n) const {
  if (std::floor(std::log2(matrix<T>::m_rows)) ==
      std::log2(matrix<T>::m_rows)) {
    std::size_t new_rows = matrix<T>::m_rows / 2,
                new_cols = matrix<T>::m_cols / 2, p = 0;
    square_matrix<T> result(new_rows);

    for (std::size_t i = m * new_cols; i < (m + 1) * new_rows; i++) {
      std::size_t q = 0;
      for (std::size_t j = n * new_cols; j < (n + 1) * new_cols; j++) {
        result.m_data[p * result.m_cols + q] =
            matrix<T>::m_data[i * matrix<T>::m_cols + j];
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
square_matrix<T>::strassen_multiply(const square_matrix<T> &src) const {
  std::size_t n = matrix<T>::m_rows;
  square_matrix<T> result(n);

  if (n == 1) {
    result.m_data[0] = matrix<T>::m_data[0] * src.m_data[0];
    return result;
  }

  square_matrix<T> s1 = src(0, 1) - src(1, 1);
  square_matrix<T> s2 = (*this)(0, 0) + (*this)(0, 1);
  square_matrix<T> s3 = (*this)(1, 0) + (*this)(1, 1);
  square_matrix<T> s4 = src(1, 0) - src(0, 0);
  square_matrix<T> s5 = (*this)(0, 0) + (*this)(1, 1);
  square_matrix<T> s6 = src(0, 0) + src(1, 1);
  square_matrix<T> s7 = (*this)(0, 1) - (*this)(1, 1);
  square_matrix<T> s8 = src(1, 0) + src(1, 1);
  square_matrix<T> s9 = (*this)(0, 0) - (*this)(1, 0);
  square_matrix<T> s10 = src(0, 0) + src(0, 1);

  square_matrix<T> p1 = (*this)(0, 0).strassen_multiply(s1);
  square_matrix<T> p2 = s2.strassen_multiply(src(1, 1));
  square_matrix<T> p3 = s3.strassen_multiply(src(0, 0));
  square_matrix<T> p4 = (*this)(1, 1).strassen_multiply(s4);
  square_matrix<T> p5 = s5.strassen_multiply(s6);
  square_matrix<T> p6 = s7.strassen_multiply(s8);
  square_matrix<T> p7 = s9.strassen_multiply(s10);

  result.assign_submatrix(0, 0, p5 + p4 - p2 + p6);
  result.assign_submatrix(0, 1, p1 + p2);
  result.assign_submatrix(1, 0, p3 + p4);
  result.assign_submatrix(1, 1, p5 + p1 - p3 - p7);

  return result;
}

template <typename T>
square_matrix<T>
square_matrix<T>::square_matrix_multiply(const square_matrix<T> &src) const {
  std::size_t n = matrix<T>::m_rows;
  square_matrix<T> result(n);

  for (std::size_t i = 0; i < n; i++) {
    for (std::size_t j = 0; j < n; j++) {
      result.m_data[i * result.m_cols + j] = 0;

      for (std::size_t k = 0; k < n; k++)
        result.m_data[i * result.m_cols + j] =
            result.m_data[i * result.m_cols + j] +
            matrix<T>::m_data[i * matrix<T>::m_cols + k] *
                src.m_data[k * src.m_cols + j];
    }
  }

  return result;
}

template <typename T>
square_matrix<T> square_matrix<T>::square_matrix_multiply_recursive(
    const square_matrix<T> &src) const {
  std::size_t n = matrix<T>::m_rows;
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

    result.assign_submatrix(0, 0,
                            (a11.square_matrix_multiply_recursive(b11)) +
                                (a12.square_matrix_multiply_recursive(b21)));
    result.assign_submatrix(0, 1,
                            (a11.square_matrix_multiply_recursive(b12)) +
                                (a12.square_matrix_multiply_recursive(b22)));
    result.assign_submatrix(1, 0,
                            (a21.square_matrix_multiply_recursive(b11)) +
                                (a22.square_matrix_multiply_recursive(b21)));
    result.assign_submatrix(1, 1,
                            (a21.square_matrix_multiply_recursive(b12)) +
                                (a22.square_matrix_multiply_recursive(b22)));
  } else if (n == 1) {
    result.m_data[0] = matrix<T>::m_data[0] * src.m_data[0];
  }

  return result;
}

template <typename T>
void square_matrix<T>::assign_submatrix(std::size_t m, std::size_t n,
                                        const square_matrix<T> &src) {
  assert(matrix<T>::m_rows % 2 == 0);
  std::size_t new_dimension = matrix<T>::m_rows / 2;
  assert(m < new_dimension || new_dimension == 1);
  assert(n < new_dimension || new_dimension == 1);

  for (std::size_t i = m * new_dimension, p = 0; i < (m + 1) * new_dimension;
       i++, p++) {
    for (std::size_t j = n * new_dimension, q = 0; j < (n + 1) * new_dimension;
         j++, q++) {
      matrix<T>::m_data[i * matrix<T>::m_cols + j] =
          src.m_data[p * new_dimension + q];
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
