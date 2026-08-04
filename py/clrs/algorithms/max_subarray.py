# Find-Maximum-Subarray algorithm from p.71-72 of CLRS 3e
def find_max_crossing_subarray(a: list, low: int, mid: int, high: int) -> tuple:
    total = a[mid]
    left_sum = total
    max_left = mid

    for i in range(mid - 1, low - 1, -1):
        total += a[i]
        if total > left_sum:
            left_sum = total
            max_left = i

    total = a[mid + 1]
    right_sum = total
    max_right = mid + 1

    for j in range(mid + 2, high + 1):
        total += a[j]
        if total > right_sum:
            right_sum = total
            max_right = j

    return (max_left, max_right, left_sum + right_sum)


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
def brute_force_find_maximum_subarray(a: list, low: int, high: int) -> tuple:
    max_low = low
    max_high = low
    max_sum = a[low]

    for i in range(low, high + 1):
        current_sum = 0
        for j in range(i, high + 1):
            current_sum += a[j]
            if current_sum > max_sum:
                max_sum = current_sum
                max_low = i
                max_high = j

    return (max_low, max_high, max_sum)


# Non-recursive Find-Maximum-Subarray algorithm from ex. 4.1-5 on p.75 of CLRS 3e
def find_maximum_subarray_non_recursive(a: list, low: int, high: int) -> tuple:
    max_low = low
    max_high = low
    max_sum = a[low]
    current_low = low
    current_sum = a[low]

    for j in range(low + 1, high + 1):
        if current_sum > 0:
            current_sum += a[j]
        else:
            current_low = j
            current_sum = a[j]

        if current_sum > max_sum:
            max_sum = current_sum
            max_low = current_low
            max_high = j

    return (max_low, max_high, max_sum)
