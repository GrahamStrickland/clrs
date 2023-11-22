#ifndef MATRIX_H
#define MATRIX_H

#include <exception>
#include <string>

template <typename T>
class Matrix {
public:
    Matrix<T>(int row, int col);
    Matrix<T>(const Matrix<T> &src);
    Matrix<T>(const std::initializer_list<std::initializer_list<T>>& list);
    ~Matrix<T>();

    Matrix<T>& operator =(const std::initializer_list<std::initializer_list<T>>& list);
    Matrix<T>& operator =(const Matrix<T> &src);
    Matrix<T> operator +(const Matrix<T> &src) const;

private:
    int m_Rows;
    int m_Cols;
    T **m_Data;
};

struct MatrixException : public std::runtime_error {
    MatrixException(const std::string& message = "Matrix exception") 
            : std::runtime_error(message) { }
};
#endif // MATRIX_H

