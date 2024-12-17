use chrono::{Duration, TimeDelta};

use std::f64::consts::LN_2;

pub fn format_number(num: f64) -> String {
    format!("{:>12.0}", num)
}

pub fn inverse_nlogn(x: f64) -> f64 {
    let max_iters = 10;
    let mut a_0 = x / (x.log2());
    let mut a_1: f64;

    for _ in 0..max_iters {
        a_1 = a_0 - (a_0 * a_0.log2() - x) / ((1.0 / LN_2) + a_0.log2());
        if ((a_1 * a_1.log2()) - (a_0 * a_0.log2())).abs() < 1.0 {
            return a_1;
        } else {
            a_0 = a_1;
        }
    }

    a_0
}

pub fn inverse_factorial(x: f64) -> f64 {
    let mut i = 0.0;
    let mut fact = 1.0;

    while fact < x {
        if i > 0.0 {
            fact *= i;
        }
        i += 1.0;
    }

    i - 1.0
}

#[cfg(test)]
mod tests {
    use super::*;

    const RUNTIMES: [TimeDelta; 7] = [
        Duration::seconds(1),
        Duration::minutes(1),
        Duration::hours(1),
        Duration::days(1),
        Duration::days(30),
        Duration::days(365),
        Duration::days(36500),
    ];

    #[test]
    fn test_inverse_nlogn() {
        let exps = vec![
            62746.0,
            2.80142e+06,
            1.33378e+08,
            2.75515e+09,
            1.77631e+10,
            7.98145e+11,
            6.86552e+13,
        ];
        let tol = 1e3;

        for (t, exp) in RUNTIMES.iter().zip(exps.iter()) {
            let time_in_microseconds = t.num_microseconds().unwrap_or(0) as f64;
            let res = inverse_nlogn(time_in_microseconds);
            assert!(
                (res - exp).abs() < tol,
                "inverse_nlogn failed: result = {}, expected = {}",
                res,
                exp
            );
        }
    }

    #[test]
    fn test_inverse_factorial() {
        let exps = vec![10.0, 12.0, 13.0, 14.0, 15.0, 17.0, 18.0];
        let tol = 1e3;

        for (t, exp) in RUNTIMES.iter().zip(exps.iter()) {
            let time_in_microseconds = t.num_microseconds().unwrap_or(0) as f64;
            let res = inverse_factorial(time_in_microseconds);
            assert!(
                (res - exp).abs() < tol,
                "inverse_nlogn failed: result = {}, expected = {}",
                res,
                exp
            );
        }
    }
}
