from math import floor, log, log2


def inverse_nlogn(x: float) -> float:
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
