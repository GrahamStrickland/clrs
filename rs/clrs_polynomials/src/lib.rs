// Horners-Rule algorithm from p.2-3 on pg. 41 of CLRS 3e
pub fn horners_rule(a: Vec<f64>, n: usize, x: f64) -> f64 {
    let mut y = 0.0;

    for i in (0..=n).rev() {
        y = a[i] + x * y;
    }

    y
}

#[cfg(test)]
mod tests {
    use super::horners_rule;

    #[test]
    fn test_horners_rule() {
        assert_eq!(horners_rule(vec![1.0], 0, 0.0), 1.0);
        assert_eq!(horners_rule(vec![1.0, 2.0], 1, 1.0), 3.0);
        assert_eq!(horners_rule(vec![1.0, 2.0, 3.0], 2, 1.0), 6.0);
        assert_eq!(horners_rule(vec![1.0, 2.0, 3.0], 2, 0.0), 1.0);
        assert_eq!(horners_rule(vec![1.0, 2.0, 3.0], 2, 2.0), 17.0);
        assert_eq!(horners_rule(vec![1.0, 2.0, 3.0], 2, 0.01), 1.0203);
        assert_eq!(horners_rule(vec![1.0, 1.0, 1.0], 2, 0.01), 1.0101);
        assert_eq!(horners_rule(vec![1.0, -1.0, 1.0], 2, 0.01), 0.9901);
        assert_eq!(horners_rule(vec![-1.0, -1.0, -1.0], 2, 0.01), -1.0101);
    }
}
