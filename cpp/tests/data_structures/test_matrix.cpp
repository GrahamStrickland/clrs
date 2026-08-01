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

BOOST_AUTO_TEST_CASE(test_initializer_list_ctor) {
  clrs::data_structures::matrix::matrix<int> A = {
      {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  clrs::data_structures::matrix::matrix<int> B(3, 3);
  B = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  BOOST_CHECK_EQUAL(A, B);
  BOOST_CHECK_EQUAL(A.tr(), 15);

  clrs::data_structures::matrix::matrix<int> C = {{1, 2}, {3, 4}, {5, 6}};
  clrs::data_structures::matrix::matrix<int> D(3, 2);
  D = {{1, 2}, {3, 4}, {5, 6}};

  BOOST_CHECK_EQUAL(C, D);
}

BOOST_AUTO_TEST_CASE(test_ragged_initializer_list_throws) {
  BOOST_CHECK_THROW(
      (clrs::data_structures::matrix::matrix<int>{{1, 2, 3}, {4, 5}}),
      clrs::data_structures::matrix::matrix_exception);

  clrs::data_structures::matrix::matrix<int> A(2, 2);
  BOOST_CHECK_THROW((A = {{1, 2}, {3}}),
                    clrs::data_structures::matrix::matrix_exception);
}

BOOST_AUTO_TEST_CASE(test_invalid_operands_throw) {
  clrs::data_structures::matrix::matrix<int> A(2, 2), B(3, 3), C(2, 3);

  BOOST_CHECK_THROW(A + B, clrs::data_structures::matrix::matrix_exception);
  BOOST_CHECK_THROW(A - B, clrs::data_structures::matrix::matrix_exception);
  BOOST_CHECK_THROW(A * B, clrs::data_structures::matrix::matrix_exception);
  BOOST_CHECK_THROW(C.tr(), clrs::data_structures::matrix::matrix_exception);
}

BOOST_AUTO_TEST_CASE(test_assignment_resizes_target) {
  clrs::data_structures::matrix::matrix<int> A(3, 3), B(2, 2);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  B = A;

  BOOST_CHECK_EQUAL(A, B);
  BOOST_CHECK_EQUAL(B.tr(), 15);
}

BOOST_AUTO_TEST_CASE(test_self_assignment) {
  clrs::data_structures::matrix::matrix<int> A(3, 3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  clrs::data_structures::matrix::matrix<int> const &alias = A;
  A = alias;

  BOOST_CHECK_EQUAL(A.tr(), 15);
  BOOST_CHECK_EQUAL(A[0], 1);
  BOOST_CHECK_EQUAL(A[8], 9);
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

BOOST_AUTO_TEST_CASE(test_strassen_multiply_padded) {
  clrs::data_structures::matrix::square_matrix<int> A(2), B(2), C(2);

  A = {{1, 3}, {7, 5}};
  B = {{6, 8}, {4, 2}};
  C = {{18, 14}, {62, 66}};

  BOOST_CHECK_EQUAL(A.strassen_multiply_padded(B), C);

  clrs::data_structures::matrix::square_matrix<int> D(3), E(3), F(3);

  D = {{1, 2, 3}, {0, 1, 4}, {5, 6, 0}};
  E = {{-1, 0, 1}, {2, 1, 0}, {0, -1, 2}};
  F = {{3, -1, 7}, {2, -3, 8}, {7, 6, 5}};

  BOOST_CHECK_EQUAL(D.strassen_multiply_padded(E), F);

  clrs::data_structures::matrix::square_matrix<int> G(4), H(4), I(4);

  G = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  H = {{1, -1, 1, -1}, {-1, 1, -1, 1}, {1, -1, 1, -1}, {-1, 1, -1, 1}};
  I = {{-2, 2, -2, 2}, {-2, 2, -2, 2}, {-2, 2, -2, 2}, {-2, 2, -2, 2}};

  BOOST_CHECK_EQUAL(G.strassen_multiply_padded(H), I);
}

BOOST_AUTO_TEST_CASE(test_square_tr) {
  clrs::data_structures::matrix::square_matrix<int> A(3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  BOOST_CHECK_EQUAL(A.tr(), 15);
}

BOOST_AUTO_TEST_CASE(test_square_initializer_list_ctor) {
  clrs::data_structures::matrix::square_matrix<int> A = {{1, 2}, {3, 4}};
  clrs::data_structures::matrix::square_matrix<int> B(2);
  B = {{1, 2}, {3, 4}};

  BOOST_CHECK_EQUAL(A, B);
  BOOST_CHECK_EQUAL(A.tr(), 5);
}

BOOST_AUTO_TEST_CASE(test_square_submatrix_of_non_power_of_two_throws) {
  clrs::data_structures::matrix::square_matrix<int> A(3);
  A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  BOOST_CHECK_THROW(A(0, 0), clrs::data_structures::matrix::matrix_exception);
}

BOOST_AUTO_TEST_SUITE_END()
