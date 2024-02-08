#include "matrix.h"

#include <complex>

template <typename T>
matrix<T>::matrix(int rows, int cols) {
    m_rows = rows;
    m_cols = cols;
    m_data = new T*[rows];

    for (int row = 0; row < rows; row++) {
        m_data[row] = new T[cols];
        for (int col = 0; col < cols; col++)
            m_data[row][col] = 0;
    }
}

template <typename T>
matrix<T>::matrix(const matrix<T> &src) {
    if (this != &src) {
        m_rows = src.m_rows;
        m_cols = src.m_cols;
        m_data = new T*[src.m_rows];

        for (int row = 0; row < src.m_rows; row++) {
            m_data[row] = new T[src.m_cols];
            for (int col = 0; col < src.m_cols; col++)
                m_data[row][col] = src.m_data[row][col];
        }
    } else {
        m_rows = 0;
        m_cols = 0;
        m_data = nullptr;
    }
}

template <typename T>
matrix<T>::matrix(const std::initializer_list<std::initializer_list<T>> &src) {
    try {
        m_rows = static_cast<int>(src.size());
        m_cols = 0;
        m_data = new T*[m_rows];

        int i = 0;

        for (const auto &row : src) {
            if (i < m_rows - 1) {
                int j = 0;
                if (i == 0)
                    m_cols = static_cast<int>(row.size());
                else if (m_cols != static_cast<int>(row.size()))
                    throw new matrix_exception(
                        "Invalid dimensions for operands passed to constructor"
                    );

                m_data[i] = new T[m_cols];
                for (const auto& element : row) {
                    if (j < m_cols - 1) {
                        m_data[i][j] = element;
                        ++j;
                    }
                }
                ++i;
            }
        }
    } catch (std::runtime_error e) {
        throw new matrix_exception(std::string(
            "Invalid operand passed to constructor: "
        ) + std::string(e.what()));
    }
}

template <typename T>
matrix<T>::~matrix() {
    for (int row = 0; row < m_rows; row++)
        delete [] m_data[row];
    delete [] m_data;
}

template <typename T>
bool matrix<T>::operator ==(const matrix<T> &src) {
    if (m_cols != src.m_cols || m_rows != src.m_rows)
        return false;

    for (int row = 0; row < m_rows; row++)
        for (int col = 0; col < m_cols; col++)
            if (m_data[row][col] != src.m_data[row][col])
                return false;

    return true;
}

template <typename T>
matrix<T>& matrix<T>::operator =(
    const std::initializer_list<std::initializer_list<T>> &src) {
    try {
        int i = 0;

        for (const auto &row : src) {
            int j = 0;

            for (const auto &element : row) {
                m_data[i][j] = element;
                ++j;
            }
            ++i;
            m_cols = j;
        }
        m_rows = i;
    } catch (std::runtime_error e) {
        throw new matrix_exception(std::string(
            "Invalid operand passed to = operator: "
        ) + std::string(e.what()));
    }

    return *this;
}

template <typename T>
matrix<T>& matrix<T>::operator =(const matrix<T> &src) {
    if (this != &src && m_rows == src.m_rows && m_cols == src.m_cols)
        for (int row = 0; row < src.m_rows; row++)
            for (int col = 0; col < src.m_cols; col++)
                m_data[row][col] = src.m_data[row][col];

    return *this;
}

template <typename T>
matrix<T> matrix<T>::operator +(const matrix<T> &src) const {
    if (m_rows == src.m_rows && m_cols == src.m_cols) { 
        matrix<T> result(m_rows, m_cols);

        for (int row = 0; row < m_rows; row++)
            for (int col = 0; col < m_cols; col++)
                result.m_data[row][col] = m_data[row][col] + src.m_data[row][col];

        return result;
    } else {
        throw new matrix_exception(
            "Invalid dimensions for operands passed to + operator"
        ); 
    }
}

template <typename T>
matrix<T> matrix<T>::operator -(const matrix<T> &src) const {
    if (m_rows == src.m_rows && m_cols == src.m_cols) { 
        matrix<T> result(m_rows, m_cols);

        for (int row = 0; row < m_rows; row++)
            for (int col = 0; col < m_cols; col++)
                result.m_data[row][col] = m_data[row][col] - src.m_data[row][col];

        return result;
    } else {
        throw new matrix_exception(
            "Invalid dimensions for operands passed to - operator"
        ); 
    }
}

template <typename T>
matrix<T> matrix<T>::operator *(const matrix<T> &src) const {
    if (m_cols == src.m_rows) { 
        matrix<T> result(m_rows, src.m_cols);

        for (int row = 0; row < result.m_rows; row++) {
            for (int col = 0; col < result.m_cols; col++) {
                result.m_data[row][col] = 0;

                for (int i = 0; i < m_cols; i++)
                    result.m_data[row][col] += m_data[row][i] * src.m_data[i][col];
            }
        }

        return result;
    } else {
        throw new matrix_exception(
            "Invalid dimensions for operands passed to * operator"
        ); 
    }
}

// See https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl for explanation
template class matrix<int>;
template class matrix<long>;
template class matrix<float>;
template class matrix<double>;
template class matrix<std::complex<int>>;
template class matrix<std::complex<long>>;
template class matrix<std::complex<float>>;
template class matrix<std::complex<double>>;
