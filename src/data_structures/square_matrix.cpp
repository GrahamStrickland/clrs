#include "square_matrix.h"

#include <complex>

template <typename T>
square_matrix<T>::square_matrix(uint8_t n) : matrix<T>(n, n) { }

template <typename T>
square_matrix<T>::square_matrix(const square_matrix<T> &src) : matrix<T>(src) { }

template <typename T>
square_matrix<T>::square_matrix(const std::initializer_list<std::initializer_list<T>> &src) 
        : matrix<T>(src) { }

template <typename T>
square_matrix<T>::~square_matrix() { }


template <typename T>
square_matrix<T>& square_matrix<T>::operator =( 
    const std::initializer_list<std::initializer_list<T>> &src) { 
    matrix<T>::operator=(src);
    return *this;
}

template <typename T>
square_matrix<T>& square_matrix<T>::operator =(const square_matrix<T> &src) { 
    matrix<T>::operator=(src);
    return *this;
}

template <typename T>
square_matrix<T> square_matrix<T>::operator *(const square_matrix<T> &src) const {
    uint8_t n = matrix<T>::m_rows;
    square_matrix<T> result(n);

    for (uint8_t i = 0; i < n; i++) {
        for (uint8_t j = 0; j < n; j++) {
            result.m_data[i][j] = 0;

            for (uint8_t k = 0; k < n; k++)
                result.m_data[i][j] = result.m_data[i][j] + matrix<T>::m_data[i][k] * src.m_data[k][j];
        }
    }

    return result;
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
