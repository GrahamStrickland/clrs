#include <boost/bind/bind.hpp>
#include <boost/test/included/unit_test.hpp>

#include "../../src/data_structures/matrix.h"
#include "../../src/data_structures/square_matrix.h"

class matrix_test {
public:
    void test_equality_op() {
        matrix<int> A(3, 3), B(3, 3);

        A = { { 1, 2, 3 } , { 4, 5, 6 }, { 7, 8, 9 } };
        B = A;

        BOOST_ASSERT(A == B);

        B = { { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 }};
        BOOST_ASSERT(!(A == B));
    }

    void test_assignment() {
        matrix<int> A(3, 3), B(3, 3);

        A = { { 1, 2, 3 } , { 4, 5, 6 }, { 7, 8, 9 } };
        B = A;

        BOOST_ASSERT(A == B);
    }

    void test_add_op() {
        matrix<int> A(3, 3), B(3, 3), C(3, 3);
        A = { { 1, 2, 3 } , { 4, 5, 6 }, { 7, 8, 9 } };
        B = { { 1, -1, 1 }, { -1, 1, -1 }, { 1, -1, 1 } };
        C = { { 2, 1, 4 }, { 3, 6, 5 }, { 8, 7, 10 } };

        BOOST_ASSERT(A + B == C);
    }

    void test_sub_op() {
        matrix<int> A(3, 3), B(3, 3), C(3, 3);
        A = { { 1, 2, 3 } , { 4, 5, 6 }, { 7, 8, 9 } };
        B = { { 1, -1, 1 }, { -1, 1, -1 }, { 1, -1, 1 } };
        C = { { 0, 3, 2 }, { 5, 4, 7 }, { 6, 9, 8 } };

        BOOST_ASSERT(A - B == C);
    }

    void test_mul_op() {
        matrix<int> A(3, 3), B(3, 3), C(3, 3);
        A = { { 1, 2, 3 } , { 4, 5, 6 }, { 7, 8, 9 } };
        B = { { 1, -1, 1 }, { -1, 1, -1 }, { 1, -1, 1 } };
        C = { { 2, -2, 2 }, { 5, -5, 5 }, { 8, -8, 8 } };

        BOOST_ASSERT(A * B == C);

        matrix<double> D(2, 3), E(3, 2), F(2, 2);
        D = { { .25, 0., 0. } , { 0., .25, 0. } };
        E = { { 0., -3 }, { -3., 0. }, { 0., 1. } };
        F = { { 0., -.75 }, { -.75, 0. } };

        BOOST_ASSERT(D * E == F);
    }

    void test_tr() {
        matrix<int> A(3, 3);
        A = { { 1, 2, 3 } , { 4, 5, 6 }, { 7, 8, 9 } };

        BOOST_ASSERT(A.tr() == 15);
    }
};

class square_matrix_test {
public:
    void test_equality_op() {
        square_matrix<int> A(3), B(3);

        A = { { 1, 2, 3 } , { 4, 5, 6 }, { 7, 8, 9 } };
        B = A;

        BOOST_ASSERT(A == B);

        B = { { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 }};
        BOOST_ASSERT(!(A == B));
    }

    void test_assignment() {
        square_matrix<int> A(3), B(3);

        A = { { 1, 2, 3 } , { 4, 5, 6 }, { 7, 8, 9 } };
        B = A;

        BOOST_ASSERT(A == B);
    }

    void test_add_op() {
        square_matrix<int> A(3), B(3), C(3);
        A = { { 1, 2, 3 } , { 4, 5, 6 }, { 7, 8, 9 } };
        B = { { 1, -1, 1 }, { -1, 1, -1 }, { 1, -1, 1 } };
        C = { { 2, 1, 4 }, { 3, 6, 5 }, { 8, 7, 10 } };

        BOOST_ASSERT(A + B == C);
    }

    void test_sub_op() {
        square_matrix<int> A(3), B(3), C(3);
        A = { { 1, 2, 3 } , { 4, 5, 6 }, { 7, 8, 9 } };
        B = { { 1, -1, 1 }, { -1, 1, -1 }, { 1, -1, 1 } };
        C = { { 0, 3, 2 }, { 5, 4, 7 }, { 6, 9, 8 } };

        BOOST_ASSERT(A - B == C);
    }

    void test_mul_op() {
        square_matrix<int> A(3), B(3), C(3);
        A = { { 1, 2, 3 } , { 4, 5, 6 }, { 7, 8, 9 } };
        B = { { 1, -1, 1 }, { -1, 1, -1 }, { 1, -1, 1 } };
        C = { { 2, -2, 2 }, { 5, -5, 5 }, { 8, -8, 8 } };

        BOOST_ASSERT(A * B == C);
    }

    void test_tr() {
        square_matrix<int> A(3);
        A = { { 1, 2, 3 } , { 4, 5, 6 }, { 7, 8, 9 } };

        BOOST_ASSERT(A.tr() == 15);
    }
};

boost::unit_test::test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[]) {
    boost::shared_ptr<matrix_test> matrix_tester(new matrix_test);

    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&matrix_test::test_equality_op, matrix_tester)));
    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&matrix_test::test_assignment, matrix_tester)));
    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&matrix_test::test_add_op, matrix_tester)));
    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&matrix_test::test_sub_op, matrix_tester)));
    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&matrix_test::test_mul_op, matrix_tester)));
    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&matrix_test::test_tr, matrix_tester)));

    boost::shared_ptr<square_matrix_test> square_matrix_tester(new square_matrix_test);

    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&square_matrix_test::test_equality_op, square_matrix_tester)));
    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&square_matrix_test::test_assignment, square_matrix_tester)));
    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&square_matrix_test::test_add_op, square_matrix_tester)));
    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&square_matrix_test::test_sub_op, square_matrix_tester)));
    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&square_matrix_test::test_mul_op, square_matrix_tester)));
    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&square_matrix_test::test_tr, square_matrix_tester)));

    return EXIT_SUCCESS;
}
