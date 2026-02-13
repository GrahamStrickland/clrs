from typing import Callable

from clrs import (brute_force_find_maximum_subarray, find_maximum_subarray,
                  find_maximum_subarray_non_recursive)

STOCK_PRICES = [
    100,
    113,
    110,
    85,
    105,
    102,
    86,
    63,
    81,
    101,
    94,
    106,
    101,
    79,
    94,
    90,
    97,
]


def assert_find_max_subarray(max_subarray_algorithm: Callable):
    daily_changes = []

    for i in range(1, len(STOCK_PRICES)):
        daily_changes.append(STOCK_PRICES[i] - STOCK_PRICES[i - 1])

    low, high, sum = max_subarray_algorithm(daily_changes, 0, len(STOCK_PRICES) - 2)

    assert low == 7
    assert high == 10
    assert sum == 43


def test_find_max_subarray():
    assert_find_max_subarray(find_maximum_subarray)


def test_brute_force_find_max_subarray():
    assert_find_max_subarray(brute_force_find_maximum_subarray)


def test_find_maximum_subarray_non_recursive():
    assert_find_max_subarray(find_maximum_subarray_non_recursive)
