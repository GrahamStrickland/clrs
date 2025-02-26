#include <boost/test/data/test_case.hpp>
#include <boost/test/included/unit_test.hpp>

#include "../../src/algorithms/search/binary_search.h"
#include "../../src/algorithms/search/linear_search.h"
#include "../../src/algorithms/search/recursive_binary_search.h"

BOOST_AUTO_TEST_SUITE(test_search)

std::array<std::array<int32_t, 8>, 4> input_vecs = {
    {{{26, 31, 41, 41, 58, 59, 101, 104}},
     {{26, 31, 41, 41, 58, 59, 101, 104}},
     {{1, 4, 5, 7, 19, 28, 45, 92}},
     {{1, 4, 5, 7, 19, 28, 45, 92}}}};
std::array<int32_t, 4> input_vals = {31, 32, 92, 101};
std::array<int32_t, 4> expected_vals = {1, -1, 7, -1};

auto test_cases = boost::unit_test::data::make(input_vecs) ^
                  boost::unit_test::data::make(input_vals) ^
                  boost::unit_test::data::make(expected_vals);

BOOST_DATA_TEST_CASE(test_linear_search, test_cases, input_arr, nu, exp) {
  auto obs = linear_search(input_arr, input_arr.size(), nu);

  BOOST_ASSERT(obs == exp);
}

BOOST_DATA_TEST_CASE(test_binary_search, test_cases, input_arr, nu, exp) {
  auto obs = binary_search(input_arr, input_arr.size(), nu);

  BOOST_ASSERT(obs == exp);
}

BOOST_DATA_TEST_CASE(test_recursive_binary_search, test_cases, input_arr, nu,
                     exp) {
  auto obs = recursive_binary_search(input_arr, nu, 0, input_arr.size());

  BOOST_ASSERT(obs == exp);
}

BOOST_AUTO_TEST_SUITE_END()
