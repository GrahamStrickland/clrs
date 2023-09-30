#include "matrix.h"

template <typename T>
Matrix<T>::Matrix(int rows, int cols) {
    m_Rows = rows;
    m_Cols = cols;
    m_Data = new T*[rows];

    for (int row = 0; row < rows; row++) {
        m_Data[row] = new T[cols];
        for (int col = 0; col < cols; col++)
            m_Data[row][col] = 0;
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for (int row = 0; row < m_Rows; row++)
        delete [] m_Data[row];
    delete [] m_Data;
}

// See https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl for explanation
template class Matrix<int>;
template class Matrix<double>;
template class Matrix<bool>;
