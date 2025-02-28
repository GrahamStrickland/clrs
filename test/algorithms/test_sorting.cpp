#include <boost/test/data/test_case.hpp>
#include <boost/test/included/unit_test.hpp>

#include "../../src/algorithms/sorting/bubble_sort.h"
#include "../../src/algorithms/sorting/insertion_sort.h"

BOOST_AUTO_TEST_SUITE(test_sorting)

int32_t input_arrs[5][8] = {{5, 2, 7, 4, 6, 1, 3, 8},
                            {31, 41, 59, 26, 41, 58, 59, 45},
                            {8, 7, 6, 5, 4, 3, 2, 1},
                            {5, 2, 4, 7, 1, 3, 2, 6},
                            {3, 41, 52, 26, 38, 57, 9, 49}};

int32_t expected_arrs[5][8] = {{1, 2, 3, 4, 5, 6, 7, 8},
                               {26, 31, 41, 41, 45, 58, 59, 59},
                               {1, 2, 3, 4, 5, 6, 7, 8},
                               {1, 2, 2, 3, 4, 5, 6, 7},
                               {3, 9, 26, 38, 41, 49, 52, 57}};

auto test_cases = boost::unit_test::data::make(input_arrs) ^
                  boost::unit_test::data::make(expected_arrs);

BOOST_DATA_TEST_CASE(test_insertion_sort, test_cases, input_arr, exp_arr) {
  insertion_sort(input_arr, 8);

  BOOST_ASSERT(input_arr == exp_arr);
}

BOOST_DATA_TEST_CASE(test_bubble_sort, test_cases, input_arr, exp_arr) {
  bubble_sort(input_arr, 8);

  BOOST_ASSERT(input_arr == exp_arr);
}

BOOST_AUTO_TEST_SUITE_END()
