#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
class Matrix {
public:
    Matrix<T>(int row, int col);
    ~Matrix<T>();

private:
    int m_Rows;
    int m_Cols;
    T **m_Data;
};
#endif // MATRIX_H
