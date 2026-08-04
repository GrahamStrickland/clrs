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


ALGORITHMS = [
    find_maximum_subarray,
    brute_force_find_maximum_subarray,
    find_maximum_subarray_non_recursive,
]

EDGE_CASES = [
    ([1, 2, -10, -10], (0, 1, 3)),
    ([-1, 5, -1], (1, 1, 5)),
    ([-5, -2, -3], (1, 1, -2)),
]


def test_max_subarray_edge_cases():
    for a, expected in EDGE_CASES:
        for algorithm in ALGORITHMS:
            assert algorithm(a, 0, len(a) - 1) == expected


def test_max_subarray_respects_subrange():
    a = [-1] * 25
    a[22] = 100
    a[23] = 100

    for algorithm in ALGORITHMS:
        assert algorithm(a, 0, 5) == (0, 0, -1)


def test_max_subarray_sum_is_int():
    for algorithm in ALGORITHMS:
        _, _, total = algorithm([3, -1, 4], 0, 2)
        assert isinstance(total, int)
