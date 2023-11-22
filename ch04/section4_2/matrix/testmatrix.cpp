#include <iostream>

#include "matrix.h"

int main(int argc, char *argv[]) {
    Matrix<int> A(3, 3); 
    Matrix<int> B(3, 3); 
    
    A = {{1, 5, 3}, {-2, 4, 5}, {3, -5, 0}};
    B = { {1, 0, -1}, {-2, 3, 6}, {8, -3, -3} };

    Matrix<int> C = A + B;

    B = A;

    return EXIT_SUCCESS;
}

