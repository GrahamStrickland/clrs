#include "../../src/algorithms/sorting/bubble_sort.h"
#include "../../src/algorithms/sorting/insertion_sort.h"
#include "test_algorithms.h"

#include <boost/test/data/test_case.hpp>
#include <boost/test/included/unit_test.hpp>

#include <cstdint>

BOOST_AUTO_TEST_SUITE(test_sorting)

namespace { // file static visibility
std::array<std::array<int32_t, 8>, 5> constexpr input_arrs{
    {{5, 2, 7, 4, 6, 1, 3, 8},
     {31, 41, 59, 26, 41, 58, 59, 45},
     {8, 7, 6, 5, 4, 3, 2, 1},
     {5, 2, 4, 7, 1, 3, 2, 6},
     {3, 41, 52, 26, 38, 57, 9, 49}}};

std::array<std::array<int32_t, 8>, 5> constexpr expected_arrs{
    {{1, 2, 3, 4, 5, 6, 7, 8},
     {26, 31, 41, 41, 45, 58, 59, 59},
     {1, 2, 3, 4, 5, 6, 7, 8},
     {1, 2, 2, 3, 4, 5, 6, 7},
     {3, 9, 26, 38, 41, 49, 52, 57}}};

auto test_cases = boost::unit_test::data::make(input_arrs) ^
                  boost::unit_test::data::make(expected_arrs);
} // namespace

BOOST_DATA_TEST_CASE(test_insertion_sort, test_cases, input_arr, exp_arr) {
  clrs::insertion_sort(input_arr);

  BOOST_CHECK_EQUAL(input_arr, exp_arr);
}

BOOST_DATA_TEST_CASE(test_bubble_sort, test_cases, input_arr, exp_arr) {
  clrs::bubble_sort(input_arr);

  BOOST_CHECK_EQUAL(input_arr, exp_arr);
}

BOOST_AUTO_TEST_SUITE_END()
