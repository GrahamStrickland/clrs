#define BOOST_TEST_MODULE boost_test_data_structures

#include "matrix.h"
#include "square_matrix.h"

#include <boost/bind/bind.hpp>
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_matrix)

BOOST_AUTO_TEST_CASE(test_equality_op) {
  clrs::data_structures::matrix::matrix<int> A(3, 3), B(3, 3);

  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = A;

  BOOST_CHECK_EQUAL(A, B);

  B = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
  BOOST_CHECK_NE(A, B);
}

BOOST_AUTO_TEST_CASE(test_assignment) {
  clrs::data_structures::matrix::matrix<int> A(3, 3), B(3, 3);

  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = A;

  BOOST_CHECK_EQUAL(A, B);
}

BOOST_AUTO_TEST_CASE(test_add_op) {
  clrs::data_structures::matrix::matrix<int> A(3, 3), B(3, 3), C(3, 3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = {{1, -1, 1}, {-1, 1, -1}, {1, -1, 1}};
  C = {{2, 1, 4}, {3, 6, 5}, {8, 7, 10}};

  BOOST_CHECK_EQUAL(A + B, C);
}

BOOST_AUTO_TEST_CASE(test_sub_op) {
  clrs::data_structures::matrix::matrix<int> A(3, 3), B(3, 3), C(3, 3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = {{1, -1, 1}, {-1, 1, -1}, {1, -1, 1}};
  C = {{0, 3, 2}, {5, 4, 7}, {6, 9, 8}};

  BOOST_CHECK_EQUAL(A - B, C);
}

BOOST_AUTO_TEST_CASE(test_mul_op) {
  clrs::data_structures::matrix::matrix<int> A(3, 3), B(3, 3), C(3, 3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = {{1, -1, 1}, {-1, 1, -1}, {1, -1, 1}};
  C = {{2, -2, 2}, {5, -5, 5}, {8, -8, 8}};

  BOOST_CHECK_EQUAL(A * B, C);

  clrs::data_structures::matrix::matrix<double> D(2, 3), E(3, 2), F(2, 2);
  D = {{.25, 0., 0.}, {0., .25, 0.}};
  E = {{0., -3}, {-3., 0.}, {0., 1.}};
  F = {{0., -.75}, {-.75, 0.}};

  BOOST_CHECK_EQUAL(D * E, F);
}

BOOST_AUTO_TEST_CASE(test_tr) {
  clrs::data_structures::matrix::matrix<int> A(3, 3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  BOOST_CHECK_EQUAL(A.tr(), 15);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(test_square_matrix)

BOOST_AUTO_TEST_CASE(test_square_equality_op) {
  clrs::data_structures::matrix::square_matrix<int> A(3), B(3);

  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = A;

  BOOST_CHECK_EQUAL(A, B);

  B = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
  BOOST_CHECK_NE(A, B);
}

BOOST_AUTO_TEST_CASE(test_square_assignment) {
  clrs::data_structures::matrix::square_matrix<int> A(3), B(3);

  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = A;

  BOOST_CHECK_EQUAL(A, B);
}

BOOST_AUTO_TEST_CASE(test_square_add_op) {
  clrs::data_structures::matrix::square_matrix<int> A(3), B(3), C(3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = {{1, -1, 1}, {-1, 1, -1}, {1, -1, 1}};
  C = {{2, 1, 4}, {3, 6, 5}, {8, 7, 10}};

  BOOST_CHECK_EQUAL(A + B, C);
}

BOOST_AUTO_TEST_CASE(test_square_sub_op) {
  clrs::data_structures::matrix::square_matrix<int> A(3), B(3), C(3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = {{1, -1, 1}, {-1, 1, -1}, {1, -1, 1}};
  C = {{0, 3, 2}, {5, 4, 7}, {6, 9, 8}};

  BOOST_CHECK_EQUAL(A - B, C);
}

BOOST_AUTO_TEST_CASE(test_square_mul_op) {
  clrs::data_structures::matrix::square_matrix<int> A(3), B(3), C(3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = {{1, -1, 1}, {-1, 1, -1}, {1, -1, 1}};
  C = {{2, -2, 2}, {5, -5, 5}, {8, -8, 8}};

  BOOST_CHECK_EQUAL(A * B, C);

  clrs::data_structures::matrix::square_matrix<int> D(2), E(2), F(2);

  D = {{1, 3}, {7, 5}};
  E = {{6, 8}, {4, 2}};
  F = {{18, 14}, {62, 66}};

  BOOST_CHECK_EQUAL(D * E, F);
}

BOOST_AUTO_TEST_CASE(test_strassen_multiply) {
  clrs::data_structures::matrix::square_matrix<int> A(2), B(2), C(2);

  A = {{1, 3}, {7, 5}};
  B = {{6, 8}, {4, 2}};
  C = {{18, 14}, {62, 66}};

  BOOST_CHECK_EQUAL(A.strassen_multiply(B), C);

  clrs::data_structures::matrix::square_matrix<int> D(4), E(4), F(4);

  D = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  E = {{1, -1, 1, -1}, {-1, 1, -1, 1}, {1, -1, 1, -1}, {-1, 1, -1, 1}};
  F = {{-2, 2, -2, 2}, {-2, 2, -2, 2}, {-2, 2, -2, 2}, {-2, 2, -2, 2}};

  BOOST_CHECK_EQUAL(D.strassen_multiply(E), F);
}

BOOST_AUTO_TEST_CASE(test_square_tr) {
  clrs::data_structures::matrix::square_matrix<int> A(3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  BOOST_CHECK_EQUAL(A.tr(), 15);
}

BOOST_AUTO_TEST_SUITE_END()
