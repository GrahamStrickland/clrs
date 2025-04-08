#define BOOST_TEST_MODULE boost_test_algorithms

#include "../../src/algorithms/search/binary_search.h"
#include "../../src/algorithms/search/linear_search.h"
#include "../../src/algorithms/search/recursive_binary_search.h"

#include <boost/test/data/test_case.hpp>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

#include <cstdint>

// make streamable for boost test:
namespace std {
std::ostream &boost_test_print_type(std::ostream &os,
                                    std::array<int32_t, 8> const &arr) {
  os << "{";
  for (char const *sep = ""; auto const &el : arr)
    os << std::exchange(sep, ", ") << el;
  return os << "}";
}
} // namespace std

BOOST_AUTO_TEST_SUITE(test_search)

namespace { // file static visibility
std::array<std::array<int32_t, 8>, 4> constexpr input_arrs{
    {{26, 31, 41, 41, 58, 59, 101, 104},
     {26, 31, 41, 41, 58, 59, 101, 104},
     {1, 4, 5, 7, 19, 28, 45, 92},
     {1, 4, 5, 7, 19, 28, 45, 92}}};
int32_t constexpr input_vals[] = {31, 32, 92, 101};
int32_t constexpr expected_vals[] = {1, -1, 7, -1};

auto test_cases = boost::unit_test::data::make(input_arrs) ^
                  boost::unit_test::data::make(input_vals) ^
                  boost::unit_test::data::make(expected_vals);
} // namespace

BOOST_DATA_TEST_CASE(test_binary_search, test_cases, input_arr, nu, exp) {
  auto obs = clrs::binary_search(std::span(input_arr), nu);

  BOOST_CHECK_EQUAL(obs, exp);
}

BOOST_DATA_TEST_CASE(test_linear_search, test_cases, input_arr, nu, exp) {
  auto obs = clrs::linear_search(std::span(input_arr), nu);

  BOOST_CHECK_EQUAL(obs, exp);
}

BOOST_DATA_TEST_CASE(test_recursive_binary_search, test_cases, input_arr, nu,
                     exp) {
  auto a = std::span(input_arr);
  auto obs = clrs::recursive_binary_search(a, nu, 0, a.size() - 1);

  BOOST_CHECK_EQUAL(obs, exp);
}

BOOST_AUTO_TEST_SUITE_END()
