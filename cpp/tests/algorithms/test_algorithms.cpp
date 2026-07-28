#define BOOST_TEST_MODULE boost_test_algorithms

#include "binary.h"
#include "max_subarray.h"
#include "polynomials.h"
#include "search.h"
#include "sorting.h"

#include <boost/test/data/test_case.hpp>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

#include <algorithm>
#include <cstdint>

// make streamable for boost test:
namespace std {
template <std::size_t N>
inline std::ostream &boost_test_print_type(std::ostream &os,
                                           std::array<int32_t, N> const &arr) {
  os << "{";
  for (char const *sep = ""; auto const &el : arr)
    os << std::exchange(sep, ", ") << el;
  return os << "}";
}

inline std::ostream &boost_test_print_type(std::ostream &os,
                                           std::vector<double> const &vec) {
  os << "{";
  for (char const *sep = ""; auto const &el : vec)
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
  auto obs = clrs::algorithms::search::binary_search(std::span(input_arr), nu);

  BOOST_CHECK_EQUAL(obs, exp);
}

BOOST_DATA_TEST_CASE(test_linear_search, test_cases, input_arr, nu, exp) {
  auto obs = clrs::algorithms::search::linear_search(std::span(input_arr), nu);

  BOOST_CHECK_EQUAL(obs, exp);
}

BOOST_DATA_TEST_CASE(test_recursive_binary_search, test_cases, input_arr, nu,
                     exp) {
  auto a = std::span(input_arr);
  auto obs =
      clrs::algorithms::search::recursive_binary_search(a, nu, 0, a.size() - 1);

  BOOST_CHECK_EQUAL(obs, exp);
}

BOOST_AUTO_TEST_CASE(test_binary_search_outside_bounds) {
  std::array<int32_t, 8> input_arr{26, 31, 41, 41, 58, 59, 101, 104};
  auto a = std::span(input_arr);

  BOOST_CHECK_EQUAL(clrs::algorithms::search::binary_search(a, 1), -1);
  BOOST_CHECK_EQUAL(clrs::algorithms::search::binary_search(a, 200), -1);
  BOOST_CHECK_EQUAL(clrs::algorithms::search::binary_search(a, 26), 0);
  BOOST_CHECK_EQUAL(clrs::algorithms::search::binary_search(a, 104), 7);

  BOOST_CHECK_EQUAL(
      clrs::algorithms::search::recursive_binary_search(a, 1, 0, a.size() - 1),
      -1);
  BOOST_CHECK_EQUAL(clrs::algorithms::search::recursive_binary_search(
                        a, 200, 0, a.size() - 1),
                    -1);
  BOOST_CHECK_EQUAL(
      clrs::algorithms::search::recursive_binary_search(a, 26, 0, a.size() - 1),
      0);
  BOOST_CHECK_EQUAL(
      clrs::algorithms::search::recursive_binary_search(a, 104, 0, a.size() - 1),
      7);
}

BOOST_AUTO_TEST_CASE(test_search_empty_span) {
  std::array<int32_t, 0> input_arr{};
  auto a = std::span(input_arr);

  BOOST_CHECK_EQUAL(clrs::algorithms::search::binary_search(a, 1), -1);
  BOOST_CHECK_EQUAL(clrs::algorithms::search::linear_search(a, 1), -1);
  BOOST_CHECK_EQUAL(
      clrs::algorithms::search::recursive_binary_search(a, 1, 0, 0), -1);
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

std::array<std::array<int32_t, 5>, 5> constexpr input_inversions_arrs{
    {{2, 3, 8, 6, 1},
     {8, 6, 3, 2, 1},
     {5, 4, 3, 2, 1},
     {1, 2, 3, 4, 5},
     {1, 3, 2, 5, 4}}};
std::array<std::size_t, 5> constexpr expected_inversions{5, 10, 10, 0, 2};

auto test_count_inversions_cases =
    boost::unit_test::data::make(input_inversions_arrs) ^
    boost::unit_test::data::make(expected_inversions);
} // namespace

BOOST_DATA_TEST_CASE(test_insertion_sort, test_cases, test_data_arr, exp_arr) {
  std::array<int32_t, 8> input_arr = test_data_arr;
  clrs::algorithms::sorting::insertion_sort(input_arr);

  BOOST_CHECK_EQUAL(input_arr, exp_arr);
}

BOOST_DATA_TEST_CASE(test_insertion_sort_reverse, test_cases, test_data_arr,
                     exp_arr) {
  std::array<int32_t, 8> input_arr = test_data_arr;
  clrs::algorithms::sorting::insertion_sort_reverse(input_arr);

  std::array<int32_t, 8> sorted_exp_arr;
  std::partial_sort_copy(exp_arr.begin(), exp_arr.end(), sorted_exp_arr.begin(),
                         sorted_exp_arr.end(), std::greater<int32_t>());

  BOOST_CHECK_EQUAL(input_arr, sorted_exp_arr);
}

BOOST_DATA_TEST_CASE(test_bubble_sort, test_cases, test_data_arr, exp_arr) {
  std::array<int32_t, 8> input_arr = test_data_arr;
  clrs::algorithms::sorting::bubble_sort(input_arr);

  BOOST_CHECK_EQUAL(input_arr, exp_arr);
}

BOOST_DATA_TEST_CASE(test_selection_sort, test_cases, test_data_arr, exp_arr) {
  std::array<int32_t, 8> input_arr = test_data_arr;
  clrs::algorithms::sorting::selection_sort(input_arr);

  BOOST_CHECK_EQUAL(input_arr, exp_arr);
}

BOOST_DATA_TEST_CASE(test_merge_sort, test_cases, test_data_arr, exp_arr) {
  std::array<int32_t, 8> input_arr = test_data_arr;
  clrs::algorithms::sorting::merge_sort(input_arr, 0, input_arr.size() - 1);

  BOOST_CHECK_EQUAL(input_arr, exp_arr);
}

BOOST_DATA_TEST_CASE(test_merge_sort_no_sentinel, test_cases, test_data_arr,
                     exp_arr) {
  std::array<int32_t, 8> input_arr = test_data_arr;
  clrs::algorithms::sorting::merge_sort_no_sentinel(input_arr, 0,
                                                    input_arr.size() - 1);

  BOOST_CHECK_EQUAL(input_arr, exp_arr);
}

BOOST_DATA_TEST_CASE(test_count_inversions, test_count_inversions_cases,
                     test_data_arr, exp_inversions) {
  std::array<int32_t, 5> input_arr = test_data_arr;
  auto inversions = clrs::algorithms::sorting::count_inversions(
      input_arr, 0, input_arr.size() - 1);

  BOOST_CHECK_EQUAL(exp_inversions, inversions);
}

BOOST_AUTO_TEST_CASE(test_insertion_sort_smallest_element_last) {
  std::array<int32_t, 4> input_arr{4, 3, 2, 1};
  std::array<int32_t, 4> const exp_arr{1, 2, 3, 4};
  clrs::algorithms::sorting::insertion_sort(input_arr);

  BOOST_CHECK_EQUAL(input_arr, exp_arr);
}

BOOST_AUTO_TEST_CASE(test_sorts_handle_empty_and_single_element_arrays) {
  std::array<int32_t, 0> empty_arr{};
  clrs::algorithms::sorting::insertion_sort(empty_arr);
  clrs::algorithms::sorting::insertion_sort_reverse(empty_arr);
  clrs::algorithms::sorting::bubble_sort(empty_arr);
  clrs::algorithms::sorting::selection_sort(empty_arr);

  BOOST_CHECK(empty_arr.empty());

  std::array<int32_t, 1> single_arr{42};
  clrs::algorithms::sorting::insertion_sort(single_arr);
  clrs::algorithms::sorting::insertion_sort_reverse(single_arr);
  clrs::algorithms::sorting::bubble_sort(single_arr);
  clrs::algorithms::sorting::selection_sort(single_arr);

  BOOST_CHECK_EQUAL(single_arr[0], 42);
}

BOOST_AUTO_TEST_CASE(test_merge_sorts_beyond_uint8_range) {
  std::array<int32_t, 300> input_arr;
  for (std::size_t i = 0; i < input_arr.size(); i++)
    input_arr[i] = static_cast<int32_t>(input_arr.size() - i);

  std::array<int32_t, 300> sentinel_arr = input_arr;
  clrs::algorithms::sorting::merge_sort(sentinel_arr, 0,
                                        sentinel_arr.size() - 1);
  BOOST_CHECK(std::is_sorted(sentinel_arr.begin(), sentinel_arr.end()));

  clrs::algorithms::sorting::merge_sort_no_sentinel(input_arr, 0,
                                                    input_arr.size() - 1);
  BOOST_CHECK(std::is_sorted(input_arr.begin(), input_arr.end()));
}

// Element values deliberately exceed INT_MAX so that an int-typed merge
// sentinel would be smaller than the data it is meant to terminate.
BOOST_AUTO_TEST_CASE(test_merge_sort_element_type_exceeding_int_max) {
  std::array<double, 8> input_arr{5e9, 2e9, 7e9, 4e9, 6e9, 1e9, 3e9, 8e9};
  std::array<double, 8> const exp_arr{1e9, 2e9, 3e9, 4e9, 5e9, 6e9, 7e9, 8e9};

  std::array<double, 8> no_sentinel_arr = input_arr;
  clrs::algorithms::sorting::merge_sort_no_sentinel(no_sentinel_arr, 0,
                                                    no_sentinel_arr.size() - 1);
  BOOST_CHECK(no_sentinel_arr == exp_arr);

  clrs::algorithms::sorting::merge_sort(input_arr, 0, input_arr.size() - 1);
  BOOST_CHECK(input_arr == exp_arr);

  std::array<double, 5> inversions_arr{2e9, 3e9, 8e9, 6e9, 1e9};
  auto inversions = clrs::algorithms::sorting::count_inversions(
      inversions_arr, 0, inversions_arr.size() - 1);

  BOOST_CHECK_EQUAL(inversions, std::size_t{5});
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

BOOST_DATA_TEST_CASE(test_binary_addition, test_cases, test_input_bitset,
                     exp_bitset) {
  std::bitset<7> input_bitset = test_input_bitset;
  const std::bitset<8> output_bitset =
      clrs::algorithms::binary::binary_addition(input_bitset,
                                                std::bitset<7>{"1111111"});

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
  return clrs::algorithms::max_subarray::find_maximum_subarray(data, 0,
                                                               data.size() - 1);
}

max_subarray_func_def constexpr algorithms[] = {
    clrs::algorithms::max_subarray::brute_force_find_max_subarray,
    find_max_subarray_func};

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
      clrs::algorithms::max_subarray::find_maximum_subarray(
          daily_changes, 0, daily_changes.size() - 1);

  BOOST_CHECK_EQUAL(low, std::size_t{7});
  BOOST_CHECK_EQUAL(high, std::size_t{10});
  BOOST_CHECK_EQUAL(sum, 43);
}

BOOST_AUTO_TEST_CASE(test_brute_force_find_max_subarray) {
  std::vector<int> daily_changes = get_daily_changes();

  const auto [low, high, sum] =
      clrs::algorithms::max_subarray::brute_force_find_max_subarray(
          daily_changes);

  BOOST_CHECK_EQUAL(low, std::size_t{7});
  BOOST_CHECK_EQUAL(high, std::size_t{10});
  BOOST_CHECK_EQUAL(sum, 43);
}

BOOST_AUTO_TEST_CASE(test_find_max_subarray_non_recursive) {
  std::vector<int> daily_changes = get_daily_changes();

  const auto [low, high, sum] =
      clrs::algorithms::max_subarray::find_maximum_subarray_non_recursive(
          daily_changes, 0, daily_changes.size() - 1);

  BOOST_CHECK_EQUAL(low, std::size_t{7});
  BOOST_CHECK_EQUAL(high, std::size_t{10});
  BOOST_CHECK_EQUAL(sum, 43);
}

BOOST_AUTO_TEST_CASE(test_hybrid_max_subarray) {
  std::vector<int> daily_changes = get_daily_changes();

  const auto [low, high, sum] =
      clrs::algorithms::max_subarray::hybrid_maximum_subarray(
          daily_changes, 0, daily_changes.size() - 1);

  BOOST_CHECK_EQUAL(low, std::size_t{7});
  BOOST_CHECK_EQUAL(high, std::size_t{10});
  BOOST_CHECK_EQUAL(sum, 43);
}

namespace { // file static visibility
using range_max_subarray_func_def =
    std::tuple<std::size_t, std::size_t, int> (*)(std::vector<int>, std::size_t,
                                                  std::size_t);

range_max_subarray_func_def constexpr range_algorithms[] = {
    clrs::algorithms::max_subarray::find_maximum_subarray,
    clrs::algorithms::max_subarray::brute_force_find_max_subarray,
    clrs::algorithms::max_subarray::find_maximum_subarray_non_recursive,
    clrs::algorithms::max_subarray::hybrid_maximum_subarray};
} // namespace

BOOST_AUTO_TEST_CASE(test_max_subarray_single_element_maximum) {
  std::vector<int> const a{-1, 5, -1};
  std::tuple<std::size_t, std::size_t, int> const exp{1, 1, 5};

  for (auto const algorithm : range_algorithms)
    BOOST_CHECK(algorithm(a, 0, a.size() - 1) == exp);
}

BOOST_AUTO_TEST_CASE(test_max_subarray_all_negative_elements) {
  std::vector<int> const a{-5, -2, -3};
  std::tuple<std::size_t, std::size_t, int> const exp{1, 1, -2};

  for (auto const algorithm : range_algorithms)
    BOOST_CHECK(algorithm(a, 0, a.size() - 1) == exp);
}

BOOST_AUTO_TEST_CASE(test_max_subarray_leading_maximum) {
  std::vector<int> const a{1, 2, -10, -10};
  std::tuple<std::size_t, std::size_t, int> const exp{0, 1, 3};

  for (auto const algorithm : range_algorithms)
    BOOST_CHECK(algorithm(a, 0, a.size() - 1) == exp);
}

BOOST_AUTO_TEST_CASE(test_max_subarray_respects_subrange) {
  std::vector<int> a(25, -1);
  a[22] = 100;
  a[23] = 100;
  std::tuple<std::size_t, std::size_t, int> const exp{0, 0, -1};

  for (auto const algorithm : range_algorithms)
    BOOST_CHECK(algorithm(a, 0, 5) == exp);
}

// Exercises the recursive branch of hybrid_maximum_subarray (n_0 >= 20), whose
// sub-problems must stay inside the requested range rather than restarting from
// the whole vector.
BOOST_AUTO_TEST_CASE(test_hybrid_max_subarray_recursive_branch) {
  std::vector<int> a(60, -1);
  a[5] = 500;
  a[30] = 50;
  a[31] = 50;
  std::tuple<std::size_t, std::size_t, int> const exp{30, 31, 100};

  for (auto const algorithm : range_algorithms)
    BOOST_CHECK(algorithm(a, 6, 59) == exp);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(test_horners_rule)

namespace { // file static visibility
std::array<std::vector<double>, 9> const input_vecs{{{1.0},
                                                     {1.0, 2.0},
                                                     {1.0, 2.0, 3.0},
                                                     {1.0, 2.0, 3.0},
                                                     {1.0, 2.0, 3.0},
                                                     {1.0, 2.0, 3.0},
                                                     {1.0, 1.0, 1.0},
                                                     {1.0, -1.0, 1.0},
                                                     {-1.0, -1.0, -1.0}}};

std::array<double, 9> constexpr input_xs{0.0,  1.0,  1.0,  0.0, 2.0,
                                         0.01, 0.01, 0.01, 0.01};

std::array<double, 9> constexpr expected_outputs{
    1.0, 3.0, 6.0, 1.0, 17.0, 1.0203, 1.0101, 0.9901, -1.0101};

auto test_cases = boost::unit_test::data::make(input_vecs) ^
                  boost::unit_test::data::make(input_xs) ^
                  boost::unit_test::data::make(expected_outputs);
} // namespace

BOOST_DATA_TEST_CASE(test_horners_rule, test_cases, input_vec, input_x,
                     exp_output) {
  auto output = clrs::algorithms::polynomials::horners_rule(input_vec, input_x);

  BOOST_CHECK_EQUAL(output, exp_output);
}

BOOST_AUTO_TEST_SUITE_END()
