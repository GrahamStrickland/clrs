#define BOOST_TEST_MODULE matrix_test

#include "../matrix/matrix.h"

#include  <boost/test/included/unit_test.hpp>

#include <iostream>

BOOST_AUTO_TEST_CASE(testInit) {
    Matrix<int> A(3, 3); 
    BOOST_TEST(A);
}

BOOST_AUTO_TEST_CASE(testAssignment) {
    Matrix<int> A(3, 3); 
    A = { { 1, 4 }, { 4, -2} };
    BOOST_TEST(A);

    Matrix<int> B(3, 3);
    B = A;
    BOOST_TEST(B ==B == AA);
}

BOOST_AUTO_TEST_CASE(testInput) {
    Matrix<int> A(3, 3);
    std::cout << "Please enter a 3x3 matrix using consecutive integers: ";
    std::cin >> A;
    BOOST_TEST(A);
}

BOOST_AUTO_TEST_CASE(testOutput) {
    Matrix<int> A(3, 3); 
    A = { { 1, 4 }, { 4, -2} };
	std::cout << "A = " << A << std::endl;
    BOOST_TEST(A);
}

BOOST_AUTO_TEST_CASE(testAssignment) {
    Matrix<int> A(3, 3); 
    Matrix<int> B(3, 3); 
    A = { { 1, 4 }, { 4, -2} };
    B = { { 0, -1 }, { 2, 15} };
    Matrix<int> C = A + B;
	std::cout << "A + B = " << C << std::endl;
    BOOST_TEST(C);
}

