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
Matrix<T>::Matrix(const Matrix<T> &src) {
    if (this != &src) {
        m_Rows = src.m_Rows;
        m_Cols = src.m_Cols;
        m_Data = new T*[src.m_Rows];

        for (int row = 0; row < src.m_Rows; row++) {
            m_Data[row] = new T[src.m_Cols];
            for (int col = 0; col < src.m_Cols; col++)
                m_Data[row][col] = src.m_Data[row][col];
        }
    }
}

template <typename T>
Matrix<T>::Matrix(const std::initializer_list<std::initializer_list<T>>& list) {
    try {
        m_Rows = static_cast<int>(list.size());
        m_Cols = static_cast<int>(list[0].size());
        m_Data = new T*[m_Rows];

        for (int row = 0; row < m_Rows; row++)
            m_Data[row] = new T[m_Cols];
            for (int col = 0; col < m_Cols; col++)
                m_Data[row][col] = src[row][col];
    } catch (std::runtime_error e) {
        throw new MatrixException(std::string("Invalid operand passed to constructor: ") 
                + std::string(e.what()));
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for (int row = 0; row < m_Rows; row++)
        delete [] m_Data[row];
    delete [] m_Data;
}

template <typename T>
Matrix<T>& Matrix<T>::operator =(const std::initializer_list<std::initializer_list<T>>& list) {
    try {
        for (int row = 0; row < m_Rows; row++)
            for (int col = 0; col < m_Cols; col++)
                m_Data[row][col] = src[row][col];
    } catch (std::runtime_error e) {
        throw new MatrixException(std::string("Invalid operand passed to = operator: ") 
                + std::string(e.what()));
    }

    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator =(const Matrix<T> &src) {
    if (this != &src && m_Rows == src.m_Rows && m_Cols == src.m_Cols)
        for (int row = 0; row < src.m_Rows; row++)
            for (int col = 0; col < src.m_Cols; col++)
                m_Data[row][col] = src.m_Data[row][col];

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator +(const Matrix<T> &src) const {
    if (m_Rows == src.m_Rows && m_Cols == src.m_Cols) { 
        Matrix<T> result(m_Rows, m_Cols);

        for (int row = 0; row < m_Rows; row++)
            for (int col = 0; col < m_Cols; col++)
                result.m_Data[row][col] += src.m_Data[row][col];

        return result;
    } else {
        throw new MatrixException("Invalid dimensions for operands passed to + operator"); 
    }
}

// See https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl for explanation
template class Matrix<int>;
template class Matrix<double>;
template class Matrix<bool>;

