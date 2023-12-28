#ifndef MATRIX_H
#define MATRIX_H

#include <istream>
#include <ostream>
#include <stdexcept>
#include <string>

template <typename T>
class Matrix {
public:
    Matrix<T>(int row, int col);
    Matrix<T>(const Matrix<T> &src);
    Matrix<T>(const std::initializer_list<std::initializer_list<T>>& list);
    ~Matrix<T>();

    Matrix<T>& operator =(
            const std::initializer_list<std::initializer_list<T>>& list);
    Matrix<T>& operator =(const Matrix<T> &src);
    Matrix<T> operator +(const Matrix<T> &src) const;

    friend std::istream& operator >>(std::istream &ins, Matrix<T> &src) {
        for (int row = 0; row < src.m_Rows; row++) {
            for (int col = 0; col < src.m_Cols; col++) {
                src.m_Data[row][col] >> ins;
            }
        }

        return ins;
    }

    friend std::ostream& operator <<(std::ostream &outs, const Matrix<T> &src) {
        outs << "\n[";
        for (int row = 0; row < src.m_Rows; row++) {
            for (int col = 0; col < src.m_Cols; col++) {
                outs << (col == 0 ? "[" : ", ") << src.m_Data[row][col];
            }
            outs << "]" << (row == src.m_Rows - 1 ? "" : ",\n");
        }
        outs << "]\n";

        return outs;
    }

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

