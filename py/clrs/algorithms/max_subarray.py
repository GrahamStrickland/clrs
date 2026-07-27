from math import inf


# Find-Maximum-Subarray algorithm from p.71-72 of CLRS 3e
def find_max_crossing_subarray(a: list, low: int, mid: int, high: int) -> tuple:
    left_sum = -inf
    sum = 0
    max_crossing_subarray = (0, 0, 0)

    for i in range(mid, low - 1, -1):
        sum += a[i]
        if sum > left_sum:
            left_sum = sum
            max_crossing_subarray = (
                i,
                max_crossing_subarray[1],
                max_crossing_subarray[2],
            )

    right_sum = -inf
    sum = 0

    for j in range(mid + 1, high + 1):
        sum += a[j]
        if sum > right_sum:
            right_sum = sum
            max_crossing_subarray = (
                max_crossing_subarray[0],
                j,
                max_crossing_subarray[2],
            )

    return (max_crossing_subarray[0], max_crossing_subarray[1], left_sum + right_sum)


def find_maximum_subarray(a: list, low: int, high: int) -> tuple:
    if high == low:
        return (low, high, a[low])

    mid = (low + high) // 2

    left_subarray = find_maximum_subarray(a, low, mid)
    right_subarray = find_maximum_subarray(a, mid + 1, high)
    cross_subarray = find_max_crossing_subarray(a, low, mid, high)

    if left_subarray[2] >= right_subarray[2] and left_subarray[2] >= cross_subarray[2]:
        return left_subarray
    elif (
        right_subarray[2] >= left_subarray[2] and right_subarray[2] >= cross_subarray[2]
    ):
        return right_subarray
    else:
        return cross_subarray


# Brute-Force-Maximum-Subarray algorithm from ex. 4.1-2 p.74 of CLRS 3e
def brute_force_find_maximum_subarray(a: list, _1: int, _2: int) -> tuple:
    max_low = 0
    max_high = 0
    max_sum = a[0]

    for i in range(len(a)):
        current_sum = 0
        for j in range(i, len(a)):
            current_sum += a[j]
            if current_sum > max_sum:
                max_sum = current_sum
                max_low = i
                max_high = j

    return (max_low, max_high, max_sum)


# Non-recursive Find-Maximum-Subarray algorithm from ex. 4.1-5 on p.75 of CLRS 3e
def find_maximum_subarray_non_recursive(a: list, low: int, high: int) -> tuple:
    j = low + 1
    max_low = 1
    max_high = 2
    max_val = a[low] + a[j]
    current_val = max_val

    while j < high:
        current_val = a[j + 1]
        for i in range(j, low - 1, -1):
            current_val += a[i]
            if max_val < current_val:
                max_low = i
                max_high = j + 1
                max_val = current_val

        j += 1

    return (max_low, max_high, max_val)
