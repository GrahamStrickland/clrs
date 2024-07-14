#include <boost/bind/bind.hpp>
#include <boost/test/included/unit_test.hpp>

#include "../../src/algorithms/search/binary_search.h"

class search_test {
public:
  void test_binary_search() {
    int32_t A[] = {26, 31, 41, 41, 58, 59};
    uint8_t len = 6;
    int32_t nu = 31;

    BOOST_ASSERT(binary_search(A, len, nu) == 1);

    nu = 32;
    BOOST_ASSERT(binary_search(A, len, nu) == -1);

    int B[] = {1, 4, 5, 7, 19, 28, 45, 92};
    len = 8;
    nu = 92;
    BOOST_ASSERT(binary_search(A, len, nu) == 7);

    nu = 101;
    BOOST_ASSERT(binary_search(A, len, nu) == -1);
  }
};

boost::unit_test::test_suite *init_unit_test_suite(int /*argc*/,
                                                   char * /*argv*/[]) {
  boost::shared_ptr<search_test> search_tester(new search_test);

  boost::unit_test::framework::master_test_suite().add(BOOST_TEST_CASE(
      boost::bind(&search_test::test_binary_search, search_tester)));

  return EXIT_SUCCESS;
}