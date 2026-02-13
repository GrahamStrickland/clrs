from datetime import timedelta

from pytest import approx

from clrs import inverse_nlogn

RUNTIMES = [
    timedelta(seconds=1),
    timedelta(minutes=1),
    timedelta(hours=1),
    timedelta(days=1),
    timedelta(days=30),
    timedelta(days=365),
    timedelta(days=36500),
]


def test_inverse_nlogn():
    tol = 1e-3

    exps = [
        62746.0,
        2801417.0,
        133378058.0,
        2755147513.0,
        71870856404.0,
        797633893349.0,
        68654697441062.0,
    ]

    for t in zip(RUNTIMES, exps):
        time_in_microseconds = t[0] / timedelta(microseconds=1)

        res = inverse_nlogn(time_in_microseconds)

        assert approx(res, tol) == t[1]
