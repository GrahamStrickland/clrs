#include <boost/bind/bind.hpp>
#include <boost/test/included/unit_test.hpp>

#include "../../src/data_structures/square_matrix.h"

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
    boost::shared_ptr<square_matrix_test> tester(new square_matrix_test);

    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&square_matrix_test::test_equality_op, tester)));
    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&square_matrix_test::test_assignment, tester)));
    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&square_matrix_test::test_add_op, tester)));
    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&square_matrix_test::test_sub_op, tester)));
    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&square_matrix_test::test_mul_op, tester)));
    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&square_matrix_test::test_tr, tester)));

    return EXIT_SUCCESS;
}
