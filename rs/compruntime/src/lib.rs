use std::f64::consts::LN_2;

pub fn fmt_f64(num: f64, width: usize, precision: usize, exp_pad: usize) -> String {
    let mut numstr = format!("{:.precision$e}", num, precision = precision);
    if numstr == "inf" {
        return format!("{:>width$}", numstr, width = width);
    } else if num.fract() == 0.0 && (num as i32) < i32::MAX {
        return format!("{:>width$}", num as i64, width = width);
    }
    let idx = match numstr.find('e') {
        Some(idx) => idx,
        None => return numstr,
    };

    let exp = numstr.split_off(idx);

    let (sign, exp) = if exp.starts_with("e-") {
        ('-', &exp[2..])
    } else {
        ('+', &exp[1..])
    };
    numstr.push_str(&format!("e{}{:0>pad$}", sign, exp, pad = exp_pad));

    format!("{:>width$}", numstr, width = width)
}

pub fn inverse_nlogn(x: f64) -> f64 {
    let max_iters = 10;
    let mut a_0 = x / (x.log2());
    let mut a_1: f64 = 0.0;

    for _ in 0..max_iters {
        a_1 = a_0 - (a_0 * a_0.log2() - x) / ((1.0 / LN_2) + a_0.log2());
        if ((a_1 * a_1.log2()) - (a_0 * a_0.log2())).abs() < 1.0 {
            return a_1.floor();
        } else {
            a_0 = a_1;
        }
    }

    a_1.floor()
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
    use chrono::{Duration, TimeDelta};

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
    fn test_fmt_f64() {
        let nums = vec![
            62746.0,
            2801417.0,
            133378058.0,
            2755147513.0,
            71870856404.0,
            797633893349.0,
            68654697441062.0,
        ];
        let exps = vec![
            "      62746",
            "    2801417",
            "  133378058",
            "2.75515e+09",
            "7.18709e+10",
            "7.97634e+11",
            "6.86547e+13",
        ];

        for (num, exp) in nums.iter().zip(exps.iter()) {
            let res = fmt_f64(*num, 11, 5, 2);
            assert_eq!(res, String::from(*exp),);
        }
    }

    #[test]
    fn test_inverse_nlogn() {
        let exps = vec![
            62746.0,
            2801417.0,
            133378058.0,
            2755147513.0,
            71870856404.0,
            797633893349.0,
            68654697441062.0,
        ];

        for (t, exp) in RUNTIMES.iter().zip(exps.iter()) {
            let time_in_microseconds = t.num_microseconds().unwrap_or(0) as f64;
            let res = inverse_nlogn(time_in_microseconds);
            let tol = 1e-3;

            assert!((res - exp).abs() / exp < tol);
        }
    }

    #[test]
    fn test_inverse_factorial() {
        let exps = vec![10.0, 12.0, 13.0, 14.0, 16.0, 17.0, 18.0];

        for (t, exp) in RUNTIMES.iter().zip(exps.iter()) {
            let time_in_microseconds = t.num_microseconds().unwrap_or(0) as f64;
            let res = inverse_factorial(time_in_microseconds);
            assert_eq!(res, *exp);
        }
    }
}
