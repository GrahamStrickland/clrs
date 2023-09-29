#include "matrix.h"

template <class T>
Matrix<class T>::Matrix(int rows, int cols) {
    m_Rows = rows;
    m_Cols = cols;
    data = new T[rows];

    for (int row = 0; row < rows; row++) {
        data[row] = new T[cols];
        for (int col = 0; col < cols; col++)
            data[row][col] = 0;
    }
}
