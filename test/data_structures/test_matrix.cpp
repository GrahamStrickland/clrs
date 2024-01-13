#define BOOST_TEST_MODULE matrix_test

#include <iostream>

#include  <boost/test/included/unit_test.hpp>

#include "../../src/data_structures/matrix.h"


BOOST_AUTO_TEST_CASE(test_constructors) {
    matrix<int> A(3, 3); 
    matrix<int> B(3, 3); 
    
    A = { { 1, 2, 3} , { 4, 5, 6}, { 7, 8, 9 } };
    B = { { 1, 0, -1} , { 0, -1, -2}, { -1, -2, -3 } };

    A = B;

    BOOST_TEST(A == B);
}

