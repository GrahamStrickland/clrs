pub mod big_o;

#[cfg(test)]
mod tests {
    use super::big_o::{inverse_factorial, inverse_nlogn};
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
