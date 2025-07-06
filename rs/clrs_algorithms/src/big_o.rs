use std::f64::consts::LN_2;

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
