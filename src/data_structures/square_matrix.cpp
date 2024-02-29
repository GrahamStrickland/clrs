#include "square_matrix.h"

#include <complex>

template <typename T>
square_matrix<T>::square_matrix(int n) : matrix<T>(n, n) { }

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

// See https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl for explanation
template class square_matrix<int>;
template class square_matrix<long>;
template class square_matrix<float>;
template class square_matrix<double>;
template class square_matrix<std::complex<int>>;
template class square_matrix<std::complex<long>>;
template class square_matrix<std::complex<float>>;
template class square_matrix<std::complex<double>>;
