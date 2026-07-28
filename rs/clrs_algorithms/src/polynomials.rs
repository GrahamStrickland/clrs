// Horners-Rule algorithm from p.2-3 on pg. 41 of CLRS 3e
pub fn horners_rule(coeffs: Vec<f64>, x: f64) -> f64 {
    let mut y = 0.0;

    for i in (0..coeffs.len()).rev() {
        y = coeffs[i] + x * y;
    }

    y
}
