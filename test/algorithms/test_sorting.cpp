#include <boost/test/data/test_case.hpp>
#include <boost/test/included/unit_test.hpp>

#include "../../src/algorithms/sorting/bubble_sort.h"
#include "../../src/algorithms/sorting/insertion_sort.h"

BOOST_AUTO_TEST_SUITE(test_sorting)

std::vector<std::vector<int32_t>> input_vecs = {{5, 2, 4, 6, 1, 3},
                                                {31, 41, 59, 26, 41, 58},
                                                {6, 5, 4, 3, 2, 1},
                                                {5, 2, 4, 7, 1, 3, 2, 6},
                                                {3, 41, 52, 26, 38, 57, 9, 49}};

std::vector<std::vector<int32_t>> expected_vecs = {
    {1, 2, 3, 4, 5, 6},
    {26, 31, 41, 41, 58, 59},
    {1, 2, 3, 4, 5, 6},
    {1, 2, 2, 3, 4, 5, 6, 7},
    {3, 9, 26, 38, 41, 49, 52, 57}};

auto test_cases = boost::unit_test::data::make(input_vecs) ^
                  boost::unit_test::data::make(expected_vecs);

BOOST_DATA_TEST_CASE(test_bubble_sort, test_cases, input_vec, exp_vec) {
  int32_t obs[input_vec.size()], exp[exp_vec.size()];

  bubble_sort(obs, input_vec.size());

  for (uint8_t i = 0; i < input_vec.size(); i++) {
    obs[i] = input_vec[i];
    exp[i] = exp_vec[i];
  }

  BOOST_ASSERT(obs == exp);
}

BOOST_DATA_TEST_CASE(test_insertion_sort, test_cases, input_vec, exp_vec) {
  int32_t obs[input_vec.size()], exp[exp_vec.size()];

  insertion_sort(obs, input_vec.size());

  for (uint8_t i = 0; i < input_vec.size(); i++) {
    obs[i] = input_vec[i];
    exp[i] = exp_vec[i];
  }

  BOOST_ASSERT(obs == exp);
}

BOOST_AUTO_TEST_SUITE_END()
