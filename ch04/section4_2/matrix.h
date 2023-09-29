#ifndef MATRIX_H
#define MATRIX_H

template <class T>
class Matrix {
public:
    Matrix<class T>(int row, int col);

private:
    int row;
    int col;
    T* data;
};
#endif // MATRIX_H
