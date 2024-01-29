#include <boost/bind/bind.hpp>
#include <boost/test/included/unit_test.hpp>

#include "../../src/data_structures/matrix.h"

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
        matrix<int> A(3, 3), B(3, 3);
        A = { { 1, 2, 3 } , { 4, 5, 6 }, { 7, 8, 9 } };
        B = { { 2, 4, 6 }, { 8, 10, 12 }, { 14, 16, 18 } };

        BOOST_ASSERT((A + A) == B);
    }
};

boost::unit_test::test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[]) {
    boost::shared_ptr<matrix_test> tester(new matrix_test);

    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&matrix_test::test_equality_op, tester)));
    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&matrix_test::test_assignment, tester)));
    boost::unit_test::framework::master_test_suite()
        .add(BOOST_TEST_CASE(boost::bind(&matrix_test::test_add_op, tester)));

    return EXIT_SUCCESS;
}
