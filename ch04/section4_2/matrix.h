#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
class Matrix {
public:
    Matrix<T>(int row, int col);
    Matrix<T>(const Matrix<T> &src);
    ~Matrix<T>();

    Matrix<T>& operator =(const Matrix<T> &src);

private:
    int m_Rows;
    int m_Cols;
    T **m_Data;
};
#endif // MATRIX_H
