#define BOOST_TEST_MODULE Matrix Test

#include "../matrix/matrix.h"

#include  <boost/test/included/unit_test.hpp>

#include <iostream>

BOOST_AUTO_TEST_CASE(test_assignment_opp) {
    matrix<int> A(3, 3); 
    matrix<int> B(3, 3); 
    
    A = { { 1, 2, 3} , { 4, 5, 6}, { 7, 8, 9 } };
    B = { { 1, 0, -1} , { 0, -1, -2}, { -1, -2, -3 } };

    A = B;

    BOOST_TEST(A == B);
}

