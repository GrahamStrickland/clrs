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

    #[test]
    fn test_inverse_nlogn() {
        let x = 1e6;
        let result = inverse_nlogn(x);
        let expected = 2e5;
        let tolerance = 1e3;

        assert!(
            (result - expected).abs() < tolerance,
            "inverse_nlogn failed: result = {}, expected = {}",
            result,
            expected
        );
    }

    #[test]
    fn test_inverse_factorial() {
        let x = 120.0;
        let result = inverse_factorial(x);
        let expected = 5.0;

        assert_eq!(
            result, expected,
            "inverse_factorial failed: result = {}, expected = {}",
            result, expected
        );

        let x_large = 6.0 * 5.0 * 4.0 * 3.0 * 2.0 * 1.0;
        let result_large = inverse_factorial(x_large);
        let expected_large = 6.0;

        assert_eq!(
            result_large, expected_large,
            "inverse_factorial failed for large value: result = {}, expected = {}",
            result_large, expected_large
        );
    }

    #[test]
    fn test_inverse_factorial_edge_cases() {
        assert_eq!(inverse_factorial(1.0), 1.0, "Failed at input 1");
        assert_eq!(inverse_factorial(2.0), 2.0, "Failed at input 2");
        assert_eq!(inverse_factorial(6.0), 3.0, "Failed at input 6");
    }
}
