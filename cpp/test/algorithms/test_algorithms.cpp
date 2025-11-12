#define BOOST_TEST_MODULE boost_test_algorithms

#include "../../src/algorithms/binary/binary_addition.h"
#include "../../src/algorithms/max_subarray/brute_force_max_subarray.h"
#include "../../src/algorithms/max_subarray/find_max_subarray.h"
#include "../../src/algorithms/max_subarray/find_max_subarray_non_recursive.h"
#include "../../src/algorithms/search/binary_search.h"
#include "../../src/algorithms/search/linear_search.h"
#include "../../src/algorithms/search/recursive_binary_search.h"
#include "../../src/algorithms/sorting/bubble_sort.h"
#include "../../src/algorithms/sorting/insertion_sort.h"
#include "../../src/algorithms/sorting/merge_sort.h"
#include "../../src/algorithms/sorting/merge_sort_no_sentinel.h"
#include "../../src/algorithms/sorting/selection_sort.h"

#include <boost/test/data/test_case.hpp>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

#include <cstdint>

// make streamable for boost test:
namespace std {
inline std::ostream &boost_test_print_type(std::ostream &os,
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

BOOST_DATA_TEST_CASE(test_insertion_sort, test_cases, const_input_arr,
                     exp_arr) {
  std::array<int32_t, 8> input_arr = const_input_arr;
  clrs::insertion_sort(input_arr);

  BOOST_CHECK_EQUAL(input_arr, exp_arr);
}

BOOST_DATA_TEST_CASE(test_bubble_sort, test_cases, const_input_arr, exp_arr) {
  std::array<int32_t, 8> input_arr = const_input_arr;
  clrs::bubble_sort(input_arr);

  BOOST_CHECK_EQUAL(input_arr, exp_arr);
}

BOOST_DATA_TEST_CASE(test_selection_sort, test_cases, const_input_arr,
                     exp_arr) {
  std::array<int32_t, 8> input_arr = const_input_arr;
  clrs::selection_sort(input_arr);

  BOOST_CHECK_EQUAL(input_arr, exp_arr);
}

BOOST_DATA_TEST_CASE(test_merge_sort, test_cases, const_input_arr, exp_arr) {
  std::array<int32_t, 8> input_arr = const_input_arr;
  clrs::merge_sort(input_arr, 0, input_arr.size() - 1);

  BOOST_CHECK_EQUAL(input_arr, exp_arr);
}

BOOST_DATA_TEST_CASE(test_merge_sort_no_sentinel, test_cases, const_input_arr,
                     exp_arr) {
  std::array<int32_t, 8> input_arr = const_input_arr;
  clrs::merge_sort_no_sentinel(input_arr, 0, input_arr.size() - 1);

  BOOST_CHECK_EQUAL(input_arr, exp_arr);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(test_binary)

namespace { // file static visibility
std::array<std::bitset<7>, 4> constexpr input_bitsets{
    std::bitset<7>{"0000000"}, std::bitset<7>{"0000001"},
    std::bitset<7>{"1000000"}, std::bitset<7>{"1000001"}};

std::array<std::bitset<8>, 4> constexpr expected_bitsets{
    std::bitset<8>{"01111111"}, std::bitset<8>{"10000000"},
    std::bitset<8>{"10111111"}, std::bitset<8>{"11000000"}};

auto test_cases = boost::unit_test::data::make(input_bitsets) ^
                  boost::unit_test::data::make(expected_bitsets);
} // namespace

BOOST_DATA_TEST_CASE(test_binary_addition, test_cases, const_input_bitset,
                     exp_bitset) {
  std::bitset<7> input_bitset = const_input_bitset;
  const std::bitset<8> output_bitset =
      clrs::binary_addition(input_bitset, std::bitset<7>{"1111111"});

  BOOST_CHECK_EQUAL(output_bitset, exp_bitset);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(test_max_subarray)

namespace { // file static visibility
constexpr std::size_t num_stocks = 17;
std::array<int, num_stocks> constexpr stock_prices = {
    100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};

std::vector<int> get_daily_changes() {
  std::vector<int> daily_changes;
  for (std::size_t i = 1; i < num_stocks; i++) {
    daily_changes.push_back(stock_prices[i] - stock_prices[i - 1]);
  }
  return daily_changes;
}

using max_subarray_func_def =
    std::tuple<std::size_t, std::size_t, int> (*)(std::vector<int>);

std::tuple<std::size_t, std::size_t, int>
find_max_subarray_func(std::vector<int> data) {
  return clrs::find_maximum_subarray(data, 0, data.size() - 1);
}

max_subarray_func_def constexpr algorithms[] = {
    clrs::brute_force_find_max_subarray, find_max_subarray_func};

auto test_cases = boost::unit_test::data::make(algorithms);
} // namespace

BOOST_DATA_TEST_CASE(test_max_subarray_algorithms, test_cases, algorithm_func) {
  std::vector<int> daily_changes = get_daily_changes();

  const auto [low, high, sum] = algorithm_func(daily_changes);

  BOOST_CHECK_EQUAL(low, std::size_t{7});
  BOOST_CHECK_EQUAL(high, std::size_t{10});
  BOOST_CHECK_EQUAL(sum, 43);
}

BOOST_AUTO_TEST_CASE(test_divide_conquer_find_max_subarray) {
  std::vector<int> daily_changes = get_daily_changes();

  const auto [low, high, sum] =
      clrs::find_maximum_subarray(daily_changes, 0, daily_changes.size() - 1);

  BOOST_CHECK_EQUAL(low, std::size_t{7});
  BOOST_CHECK_EQUAL(high, std::size_t{10});
  BOOST_CHECK_EQUAL(sum, 43);
}

BOOST_AUTO_TEST_CASE(test_brute_force_find_max_subarray) {
  std::vector<int> daily_changes = get_daily_changes();

  const auto [low, high, sum] =
      clrs::brute_force_find_max_subarray(daily_changes);

  BOOST_CHECK_EQUAL(low, std::size_t{7});
  BOOST_CHECK_EQUAL(high, std::size_t{10});
  BOOST_CHECK_EQUAL(sum, 43);
}

BOOST_AUTO_TEST_CASE(test_find_max_subarray_non_recursive) {
  std::vector<int> daily_changes = get_daily_changes();

  const auto [low, high, sum] = clrs::find_maximum_subarray_non_recursive(
      daily_changes, 0, daily_changes.size() - 1);

  BOOST_CHECK_EQUAL(low, std::size_t{7});
  BOOST_CHECK_EQUAL(high, std::size_t{10});
  BOOST_CHECK_EQUAL(sum, 43);
}

BOOST_AUTO_TEST_SUITE_END()
