#include <complex>

#include "matrix.h"

namespace clrs {
namespace data_structures {
namespace matrix {
template <typename T> matrix<T>::matrix(std::size_t rows, std::size_t cols) {
  m_rows = rows;
  m_cols = cols;
  m_data = new T[rows * cols];

  for (std::size_t row = 0; row < rows; row++) {
    for (std::size_t col = 0; col < cols; col++)
      m_data[row * cols + col] = 0;
  }
}

template <typename T> matrix<T>::matrix(const matrix<T> &src) {
  m_rows = src.m_rows;
  m_cols = src.m_cols;
  m_data = new T[src.m_rows * src.m_cols];

  for (std::size_t row = 0; row < src.m_rows; row++) {
    for (std::size_t col = 0; col < src.m_cols; col++)
      m_data[row * m_cols + col] = src.m_data[row * src.m_cols + col];
  }
}

template <typename T>
matrix<T>::matrix(const std::initializer_list<std::initializer_list<T>> &src) {
  m_rows = src.size();
  m_cols = m_rows > 0 ? src.begin()->size() : 0;

  for (const auto &row : src)
    if (row.size() != m_cols)
      throw matrix_exception(
          "Invalid dimensions for operands passed to constructor");

  m_data = new T[m_rows * m_cols];

  std::size_t i = 0;

  for (const auto &row : src) {
    std::size_t j = 0;

    for (const auto &element : row) {
      m_data[i * m_cols + j] = element;
      ++j;
    }
    ++i;
  }
}

template <typename T> matrix<T>::~matrix() { delete[] m_data; }

template <typename T> bool matrix<T>::operator==(const matrix<T> &src) const {
  if (m_cols != src.m_cols || m_rows != src.m_rows)
    return false;

  for (std::size_t row = 0; row < m_rows; row++)
    for (std::size_t col = 0; col < m_cols; col++)
      if (m_data[row * m_cols + col] != src.m_data[row * src.m_cols + col])
        return false;

  return true;
}

template <typename T>
matrix<T> &matrix<T>::operator=(
    const std::initializer_list<std::initializer_list<T>> &src) {
  std::size_t rows = src.size();
  std::size_t cols = rows > 0 ? src.begin()->size() : 0;

  for (const auto &row : src)
    if (row.size() != cols)
      throw matrix_exception("Invalid operand passed to = operator");

  T *data = new T[rows * cols];
  std::size_t i = 0;

  for (const auto &row : src) {
    std::size_t j = 0;

    for (const auto &element : row) {
      data[i * cols + j] = element;
      ++j;
    }
    ++i;
  }

  delete[] m_data;
  m_data = data;
  m_rows = rows;
  m_cols = cols;

  return *this;
}

template <typename T> matrix<T> &matrix<T>::operator=(const matrix<T> &src) {
  if (this == &src)
    return *this;

  if (m_rows != src.m_rows || m_cols != src.m_cols) {
    T *data = new T[src.m_rows * src.m_cols];
    delete[] m_data;
    m_data = data;
    m_rows = src.m_rows;
    m_cols = src.m_cols;
  }

  for (std::size_t row = 0; row < src.m_rows; row++)
    for (std::size_t col = 0; col < src.m_cols; col++)
      m_data[row * m_cols + col] = src.m_data[row * src.m_cols + col];

  return *this;
}

template <typename T>
matrix<T> matrix<T>::operator+(const matrix<T> &src) const {
  if (m_rows == src.m_rows && m_cols == src.m_cols) {
    matrix<T> result(m_rows, m_cols);

    for (std::size_t row = 0; row < m_rows; row++)
      for (std::size_t col = 0; col < m_cols; col++)
        result.m_data[row * result.m_cols + col] =
            m_data[row * m_cols + col] + src.m_data[row * src.m_cols + col];

    return result;
  } else {
    throw matrix_exception(
        "Invalid dimensions for operands passed to + operator");
  }
}

template <typename T>
matrix<T> matrix<T>::operator-(const matrix<T> &src) const {
  if (m_rows == src.m_rows && m_cols == src.m_cols) {
    matrix<T> result(m_rows, m_cols);

    for (std::size_t row = 0; row < m_rows; row++)
      for (std::size_t col = 0; col < m_cols; col++)
        result.m_data[row * result.m_cols + col] =
            m_data[row * m_cols + col] - src.m_data[row * src.m_cols + col];

    return result;
  } else {
    throw matrix_exception(
        "Invalid dimensions for operands passed to - operator");
  }
}

template <typename T>
matrix<T> matrix<T>::operator*(const matrix<T> &src) const {
  if (m_cols == src.m_rows) {
    matrix<T> result(m_rows, src.m_cols);

    for (std::size_t row = 0; row < result.m_rows; row++) {
      for (std::size_t col = 0; col < result.m_cols; col++) {
        result.m_data[row * result.m_cols + col] = static_cast<T>(0);

        for (std::size_t i = 0; i < m_cols; i++)
          result.m_data[row * result.m_cols + col] +=
              m_data[row * m_cols + i] * src.m_data[i * src.m_cols + col];
      }
    }

    return result;
  } else {
    throw matrix_exception(
        "Invalid dimensions for operands passed to * operator");
  }
}

template <typename T> T matrix<T>::operator[](std::size_t index) {
  return m_data[index];
}

template <typename T> T matrix<T>::tr() {
  T tr = static_cast<T>(0);

  if (m_rows == m_cols) {
    for (std::size_t i = 0; i < m_rows; i++)
      tr += m_data[i * m_cols + i];

    return tr;
  } else {
    throw matrix_exception(
        "Invalid dimensions, only valid for square matrices");
  }
}

// See https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl for
// explanation
template class matrix<int>;
template class matrix<long>;
template class matrix<float>;
template class matrix<double>;
template class matrix<std::complex<int>>;
template class matrix<std::complex<long>>;
template class matrix<std::complex<float>>;
template class matrix<std::complex<double>>;
} // namespace matrix
} // namespace data_structures
} // namespace clrs
