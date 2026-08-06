from math import floor, log, log2


def inverse_nlogn(x: float) -> float:
    """
    Computes the inverse of `n log(n)`.

    Args:
        x: The value `x` such that `n log(n) = x`.

    Returns:
        A floating point approximation to the value `n` such that `n log(n) = x`.
    """
    max_iters = 10
    a_0 = x / log2(x)
    a_1 = 0.0

    for _ in range(0, max_iters):
        a_1 = a_0 - (a_0 * log2(a_0) - x) / ((1.0 / log(2)) + log2(a_0))
        if abs(a_1 * log2(a_1) - (a_0 * log2(a_0))) < 1.0:
            return floor(a_1)
        else:
            a_0 = a_1

    return floor(a_1)


def inverse_factorial(x: float) -> float:
    """
    Computes the inverse of `n!`, i.e. the largest `n` such that `n! <= x`.

    Args:
        x: The value `x` such that `n! = x`.

    Returns:
        An floating point approximation to the value `n` such that `n log(n) = x`.
    """
    n = 0
    fact = 1

    while fact * (n + 1) <= x:
        n += 1
        fact *= n

    return n
