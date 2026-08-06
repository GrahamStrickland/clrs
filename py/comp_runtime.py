import math
from datetime import timedelta

from clrs.algorithms.big_o import inverse_nlogn, inverse_factorial

RUNTIMES = [
    timedelta(seconds=1),
    timedelta(minutes=1),
    timedelta(hours=1),
    timedelta(days=1),
    timedelta(days=30),
    timedelta(days=365),
    timedelta(days=36500),
]
HEADINGS = ["1 second", "1 minute", "1 hour", "1 day", "1 month", "1 year", "1 century"]

LABEL_WIDTH = 8
CELL_WIDTH = 16
PRECISION = 5

RULE = "-" * (LABEL_WIDTH + CELL_WIDTH * len(HEADINGS))


def print_n(n: float | str):
    match n:
        case float():
            if n < 1e12:
                n = int(n)
                print(f"{n:>{CELL_WIDTH}}", end="")
            else:
                print(f"{n:{CELL_WIDTH}.{PRECISION}g}", end="")
        case _:
            print(f"{n:>{CELL_WIDTH}}", end="")


def main():
    print("""Comparison of running times for the largest problem size n of a problem that can be solved in time t, 
assuming that the algorithm to solve the problem takes f(n) microseconds:""")
    print(RULE)
    print(f"{'f(n)':>{LABEL_WIDTH}}", end="")
    for heading in HEADINGS:
        print(f"{heading:>{CELL_WIDTH}}", end="")
    print("\n" + RULE)

    print(f"{'lg(n)':>{LABEL_WIDTH}}", end="")
    for duration in RUNTIMES:
        try:
            smallest_n = 2.0 ** (duration / timedelta(microseconds=1))
        except OverflowError:
            smallest_n = "∞"
        print_n(smallest_n)

    print(f"\n{'sqrt(n)':>{LABEL_WIDTH}}", end="")
    for duration in RUNTIMES:
        try:
            smallest_n = (duration / timedelta(microseconds=1)) ** 2.0
        except OverflowError:
            smallest_n = "∞"
        print_n(smallest_n)

    print(f"\n{'n':>{LABEL_WIDTH}}", end="")
    for duration in RUNTIMES:
        try:
            smallest_n = duration / timedelta(microseconds=1)
        except OverflowError:
            smallest_n = "∞"
        print_n(smallest_n)

    print(f"\n{'nlg(n)':>{LABEL_WIDTH}}", end="")
    for duration in RUNTIMES:
        try:
            smallest_n = inverse_nlogn((duration / timedelta(microseconds=1)))
        except OverflowError:
            smallest_n = "∞"
        print_n(smallest_n)

    print(f"\n{'n^2':>{LABEL_WIDTH}}", end="")
    for duration in RUNTIMES:
        try:
            smallest_n = math.sqrt((duration / timedelta(microseconds=1)))
        except OverflowError:
            smallest_n = "∞"
        print_n(smallest_n)

    print(f"\n{'n^3':>{LABEL_WIDTH}}", end="")
    for duration in RUNTIMES:
        try:
            smallest_n = math.cbrt((duration / timedelta(microseconds=1)))
        except OverflowError:
            smallest_n = "∞"
        print_n(smallest_n)

    print(f"\n{'2^n':>{LABEL_WIDTH}}", end="")
    for duration in RUNTIMES:
        try:
            smallest_n = math.log((duration / timedelta(microseconds=1))) / math.log(
                2.0
            )
        except OverflowError:
            smallest_n = "∞"
        print_n(smallest_n)

    print(f"\n{'n!':>{LABEL_WIDTH}}", end="")
    for duration in RUNTIMES:
        try:
            smallest_n = inverse_factorial((duration / timedelta(microseconds=1)))
        except OverflowError:
            smallest_n = "∞"
        print_n(smallest_n)

    print("\n" + RULE)


if __name__ == "__main__":
    main()
