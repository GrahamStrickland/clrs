#define BOOST_TEST_MODULE boost_test_data_structures

#include "../../src/data_structures/matrix.h"
#include "../../src/data_structures/square_matrix.h"

#include <boost/bind/bind.hpp>
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_matrix)

BOOST_AUTO_TEST_CASE(test_equality_op) {
  clrs::matrix<int> A(3, 3), B(3, 3);

  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = A;

  BOOST_CHECK_EQUAL(A, B);

  B = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
  BOOST_CHECK_NE(A, B);
}

BOOST_AUTO_TEST_CASE(test_assignment) {
  clrs::matrix<int> A(3, 3), B(3, 3);

  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = A;

  BOOST_CHECK_EQUAL(A, B);
}

BOOST_AUTO_TEST_CASE(test_add_op) {
  clrs::matrix<int> A(3, 3), B(3, 3), C(3, 3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = {{1, -1, 1}, {-1, 1, -1}, {1, -1, 1}};
  C = {{2, 1, 4}, {3, 6, 5}, {8, 7, 10}};

  BOOST_CHECK_EQUAL(A + B, C);
}

BOOST_AUTO_TEST_CASE(test_sub_op) {
  clrs::matrix<int> A(3, 3), B(3, 3), C(3, 3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = {{1, -1, 1}, {-1, 1, -1}, {1, -1, 1}};
  C = {{0, 3, 2}, {5, 4, 7}, {6, 9, 8}};

  BOOST_CHECK_EQUAL(A - B, C);
}

BOOST_AUTO_TEST_CASE(test_mul_op) {
  clrs::matrix<int> A(3, 3), B(3, 3), C(3, 3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = {{1, -1, 1}, {-1, 1, -1}, {1, -1, 1}};
  C = {{2, -2, 2}, {5, -5, 5}, {8, -8, 8}};

  BOOST_CHECK_EQUAL(A * B, C);

  clrs::matrix<double> D(2, 3), E(3, 2), F(2, 2);
  D = {{.25, 0., 0.}, {0., .25, 0.}};
  E = {{0., -3}, {-3., 0.}, {0., 1.}};
  F = {{0., -.75}, {-.75, 0.}};

  BOOST_CHECK_EQUAL(D * E, F);
}

BOOST_AUTO_TEST_CASE(test_tr) {
  clrs::matrix<int> A(3, 3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  BOOST_CHECK_EQUAL(A.tr(), 15);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(test_square_matrix)

BOOST_AUTO_TEST_CASE(test_equality_op) {
  clrs::square_matrix<int> A(3), B(3);

  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = A;

  BOOST_CHECK_EQUAL(A, B);

  B = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
  BOOST_CHECK_NE(A, B);
}

BOOST_AUTO_TEST_CASE(test_assignment) {
  clrs::square_matrix<int> A(3), B(3);

  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = A;

  BOOST_CHECK_EQUAL(A, B);
}

BOOST_AUTO_TEST_CASE(test_add_op) {
  clrs::square_matrix<int> A(3), B(3), C(3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = {{1, -1, 1}, {-1, 1, -1}, {1, -1, 1}};
  C = {{2, 1, 4}, {3, 6, 5}, {8, 7, 10}};

  BOOST_CHECK_EQUAL(A + B, C);
}

BOOST_AUTO_TEST_CASE(test_sub_op) {
  clrs::square_matrix<int> A(3), B(3), C(3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = {{1, -1, 1}, {-1, 1, -1}, {1, -1, 1}};
  C = {{0, 3, 2}, {5, 4, 7}, {6, 9, 8}};

  BOOST_CHECK_EQUAL(A - B, C);
}

BOOST_AUTO_TEST_CASE(test_mul_op) {
  clrs::square_matrix<int> A(3), B(3), C(3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = {{1, -1, 1}, {-1, 1, -1}, {1, -1, 1}};
  C = {{2, -2, 2}, {5, -5, 5}, {8, -8, 8}};

  BOOST_CHECK_EQUAL(A * B, C);

  clrs::square_matrix<int> D(2), E(2), F(2);

  D = {{1, 3}, {7, 5}};
  E = {{6, 8}, {4, 2}};
  F = {{18, 14}, {62, 66}};

  BOOST_CHECK_EQUAL(D * E, F);
}

BOOST_AUTO_TEST_CASE(test_tr) {
  clrs::square_matrix<int> A(3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  BOOST_CHECK_EQUAL(A.tr(), 15);
}

BOOST_AUTO_TEST_SUITE_END()
