#include <iostream>

#include "matrix.h"

template <typename T>
void testOutput(Matrix<T> &A, Matrix<T> &B);

template <typename T>
void testAssignment(Matrix<T> &A, Matrix<T> &B);

int main(int argc, char *argv[]) {
    Matrix<int> A(3, 3); 
    Matrix<int> B(3, 3); 
    
    A = {{1, 5, 3}, {-2, 4, 5}, {3, -5, 0}};
    B = { {1, 0, -1}, {-2, 3, 6}, {8, -3, -3} };

    testOutput(A, B);
    testAssignment(A, B);

    return EXIT_SUCCESS;
}

template <typename T>
void testOutput(Matrix<T> &A, Matrix<T> &B) {
	std::cout << "A = " << A << std::endl;
	std::cout << "B = " << B << std::endl;

    B = A;

	std::cout << "After B = A, B = " << B << std::endl;
}

template <typename T>
void testAssignment(Matrix<T>& A, Matrix<T>& B) {
    Matrix<int> C = A + B;

	std::cout << "A + B = " << C << std::endl;
}

