#include <complex>

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
    } else {
        m_Rows = 0;
        m_Cols = 0;
        m_Data = nullptr;
    }
}

template <typename T>
Matrix<T>::Matrix(const std::initializer_list<std::initializer_list<T>> &src) {
    try {
        m_Rows = static_cast<int>(src.size());
        m_Cols = 0;
        m_Data = new T*[m_Rows];

        int i = 0;

        for (const auto &row : src) {
            if (i < m_Rows - 1) {
                int j = 0;
                if (i == 0)
                    m_Cols = static_cast<int>(row.size());
                else if (m_Cols != static_cast<int>(row.size()))
                    throw new MatrixException("Invalid dimensions for operands passed to constructor");

                m_Data[i] = new T[m_Cols];

                for (const auto& element : row) {
                    if (j < m_Cols - 1) {
                        m_Data[i][j] = element;
                        ++j;
                    }
                }
                ++i;
            }
        }
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
Matrix<T>& Matrix<T>::operator =(const std::initializer_list<std::initializer_list<T>> &src) {
    try {
        int i = 0;

        for (const auto &row : src) {
            int j = 0;

            for (const auto &element : row) {
                m_Data[i][j] = element;
                ++j;
            }
            ++i;
        }
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

template <typename T>
std::istream& operator >>(std::istream &ins, Matrix<T> &src) {
    for (int row = 0; row < src.m_Rows; row++) {
        for (int col = 0; col < src.m_Cols; col++) {
            ins >> src.m_Data[row][col];
        }
    }

	return ins; 
}

template <typename T>
std::ostream& operator <<(std::ostream &outs, const Matrix<T> &src) {
    for (int row = 0; row < src.m_Rows; row++) {
        outs << '[';
        for (int col = 0; col < src.m_Cols; col++) {
            outs << (col == 0 ? "[" : ", ") << src.m_Data[row][col];
        }
        outs << "]\n";
    }
    outs << "]\n";

    return outs;
}

// See https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl for explanation
template class Matrix<int>;
template class Matrix<long>;
template class Matrix<float>;
template class Matrix<double>;
template class Matrix<std::complex<int>>;
template class Matrix<std::complex<long>>;
template class Matrix<std::complex<float>>;
template class Matrix<std::complex<double>>;

