#ifndef MATRIX_H
#define MATRIX_H

#include <initializer_list>
#include <ostream>
#include <stdexcept>
#include <string>

namespace clrs {
template <typename T> class matrix {
public:
  matrix<T>(std::size_t row, std::size_t col);
  matrix<T>(const matrix<T> &src);
  matrix<T>(const std::initializer_list<std::initializer_list<T>> &src);
  ~matrix<T>();

  bool operator==(const matrix<T> &src) const;
  matrix<T> &
  operator=(const std::initializer_list<std::initializer_list<T>> &src);
  matrix<T> &operator=(const matrix<T> &src);
  matrix<T> operator+(const matrix<T> &src) const;
  matrix<T> operator-(const matrix<T> &src) const;
  matrix<T> operator*(const matrix<T> &src) const;

  T operator[](std::size_t index);
  T tr();

  friend std::ostream &operator<<(std::ostream &outs, const matrix<T> &src) {
    outs << "\n[";
    for (std::size_t row = 0; row < src.m_rows; row++) {
      for (std::size_t col = 0; col < src.m_cols; col++) {
        outs << (col == 0 ? "[" : ", ") << src.m_data[row * src.m_cols + col];
      }
      outs << "]" << (row == src.m_rows - 1 ? "" : ",\n");
    }
    outs << "]\n";

    return outs;
  }

protected:
  std::size_t m_rows;
  std::size_t m_cols;
  T *m_data;
};

struct matrix_exception : public std::runtime_error {
  matrix_exception(const std::string &message = "Matrix exception")
      : std::runtime_error(message) {}
};
} // namespace clrs
#endif // MATRIX_H
