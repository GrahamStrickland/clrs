#include <cassert>
#include <iostream>

#include "matrix.h"

bool testInput();

template <typename T>
bool testOutput(Matrix<T> &A, Matrix<T> &B);

template <typename T>
bool testAssignment(Matrix<T> &A, Matrix<T> &B);

int main(int argc, char *argv[]) {
    Matrix<int> A(3, 3); 
    Matrix<int> B(3, 3); 
    
    A = { {1, 5, 3}, {-2, 4, 5}, {3, -5, 0} };
    B = { {1, 0, -1}, {-2, 3, 6}, {8, -3, -3} };

    bool result = testInput();
    assert(result == true);
    result = testOutput(A, B);
    assert(result == true);
    result = testAssignment(A, B);
    assert(result == true);

    return EXIT_SUCCESS;
}

bool testInput() {
    Matrix<int> A(3, 3);
    std::cout << "Please enter a 3x3 matrix using consecutive integers: ";
    std::cin >> A;

    return true;
}

template <typename T>
bool testOutput(Matrix<T> &A, Matrix<T> &B) {
	std::cout << "A = " << A << std::endl;
	std::cout << "B = " << B << std::endl;

    B = A;

	std::cout << "After B = A, B = " << B << std::endl;

    return B == A;
}

template <typename T>
bool testAssignment(Matrix<T>& A, Matrix<T>& B) {
    Matrix<int> C = A + B;

	std::cout << "A + B = " << C << std::endl;

    return true;
}

