#ifndef MATRIX_H
#define MATRIX_H

#include <initializer_list>
#include <ostream>
#include <stdexcept>
#include <string>

template <typename T> class matrix {
public:
  matrix<T>(uint8_t row, uint8_t col);
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

  T *operator[](uint8_t index);
  T tr();

  friend std::ostream &operator<<(std::ostream &outs, const matrix<T> &src) {
    outs << "\n[";
    for (uint8_t row = 0; row < src.m_rows; row++) {
      for (uint8_t col = 0; col < src.m_cols; col++) {
        outs << (col == 0 ? "[" : ", ") << src.m_data[row][col];
      }
      outs << "]" << (row == src.m_rows - 1 ? "" : ",\n");
    }
    outs << "]\n";

    return outs;
  }

protected:
  uint8_t m_rows;
  uint8_t m_cols;
  T **m_data;
};

struct matrix_exception : public std::runtime_error {
  matrix_exception(const std::string &message = "Matrix exception")
      : std::runtime_error(message) {}
};
#endif // MATRIX_H
