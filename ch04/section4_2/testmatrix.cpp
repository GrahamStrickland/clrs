#include <iostream>

#include "matrix.h"

int main(int argc, char *argv[]) {
    Matrix<int> A(3, 3);
    Matrix<int> B(3, 3);

    B = A;

    return EXIT_SUCCESS;
}
