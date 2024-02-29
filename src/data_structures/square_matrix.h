#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H

#include "matrix.h"

template <typename T>
class square_matrix: public matrix<T> {
public:
    square_matrix<T>(int n);
    square_matrix<T>(const square_matrix<T> &src);
    square_matrix<T>(const std::initializer_list<std::initializer_list<T>> &src); 
    ~square_matrix<T>();

    square_matrix<T>& operator =(
            const std::initializer_list<std::initializer_list<T>> &src);
    square_matrix<T>& operator =(const square_matrix<T> &src);
    square_matrix<T> operator *(const square_matrix<T> &src) const;
};
#endif // SQUARE_MATRIX_H