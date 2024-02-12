#include "square_matrix.h"

#include <complex>

template <typename T>
square_matrix<T>::square_matrix(int n) : matrix<T>(n, n) {
    // Deliberately blank
}

template <typename T>
square_matrix<T>::square_matrix(const square_matrix<T> &src) : matrix<T>(src) {
    if (src.m_rows != src.m_cols)
        throw new matrix_exception(
            "Invalid dimensions, number of columns must equal number of rows"
        ); 
}

template <typename T>
square_matrix<T>::square_matrix(const std::initializer_list<std::initializer_list<T>> &src) 
        : matrix<T>(src) {
    m_rows = static_cast<int>(src.size());

    for (const auto &row : src) {
        m_cols = static_cast<int>(row.size());
        
        if (m_rows != m_cols)
            throw new matrix_exception(
                "Invalid dimensions, number of columns must equal number of rows"
            ); 
    }
}

// See https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl for explanation
template class square_matrix<int>;
template class square_matrix<long>;
template class square_matrix<float>;
template class square_matrix<double>;
template class square_matrix<std::complex<int>>;
template class square_matrix<std::complex<long>>;
template class square_matrix<std::complex<float>>;
template class square_matrix<std::complex<double>>;
