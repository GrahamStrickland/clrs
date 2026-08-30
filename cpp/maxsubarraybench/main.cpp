#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string_view>
#include <vector>

#include "max_subarray.h"

std::vector<int> get_daily_changes(std::vector<int> stock_prices,
                                   std::size_t num_stocks) {
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

std::tuple<max_subarray_func_def,
           std::string_view> constexpr algorithms_and_names[] = {
    {clrs::algorithms::max_subarray::brute_force_find_max_subarray,
     std::string_view("brute_force_find_max_subarray")},
    {find_max_subarray_func, std::string_view("find_max_subarray")}};

template <typename func_type>
void benchmark_algorithm(std::vector<int> stock_prices, std::size_t num_stocks,
                         func_type algorithm_func,
                         std::string_view algorithm_name) {
  std::vector<int> daily_changes = get_daily_changes(stock_prices, num_stocks);

  auto start = std::chrono::high_resolution_clock::now();
  const std::tuple<std::size_t, std::size_t, int> result =
      algorithm_func(daily_changes);
  asm volatile("" : : "g"(&result) : "memory");

  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double, std::milli> duration = end - start;

  std::cout << "Execution time for algorithm \"" << algorithm_name
            << "\": " << duration.count() << " ms\n";
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Error: Please an integer argument greater than 3 for the "
                 "maximum size of "
                 "array used in benchmarking.\n";
    std::cerr << "Usage: " << argv[0] << " <number>\n";
    return EXIT_FAILURE;
  }

  std::size_t max_array_size;
  try {
    unsigned long long arg = std::stoull(argv[1]);
    max_array_size = static_cast<std::size_t>(arg);
  } catch (const std::invalid_argument &e) {
    std::cerr << "Error: The argument provided is not a valid integer.\n";
    return EXIT_FAILURE;
  } catch (const std::out_of_range &e) {
    std::cerr << "Error: The number provided is too large.\n";
    return EXIT_FAILURE;
  }

  if (max_array_size < 3) {
    std::cerr << "Error: Please enter an integer amount greater than 3.\n";
    return EXIT_FAILURE;
  }

  std::srand(std::time({}));

  std::vector<int> stock_prices;
  stock_prices.reserve(max_array_size);
  for (std::size_t num_stocks = 3; num_stocks <= max_array_size; num_stocks++) {
    std::cout << "============================\n"
              << "Results for array of size " << num_stocks << ":\n"
              << "============================\n";
    stock_prices.clear();
    for (std::size_t i = 0; i < num_stocks; i++) {
      stock_prices.push_back(std::rand());
    }

    for (auto const &[func, name] : algorithms_and_names) {
      benchmark_algorithm(stock_prices, num_stocks, func, name);
    }
  }

  return EXIT_SUCCESS;
}
