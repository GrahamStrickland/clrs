pub mod matrix;

#[cfg(test)]
mod tests {
    // Matrix tests
    use super::matrix::Matrix;

    #[test]
    fn test_matrix() {
        let a: Matrix<i32> = Matrix::new(2, 2);
    }

    #[test]
    fn test_add() {
        let a: Matrix<i32> = Matrix::new(2, 2);
        let b: Matrix<i32> = Matrix::new(2, 2);

        let c = a + b;

        let d: Matrix<f64> = Matrix::new(2, 2);
        let e: Matrix<f64> = Matrix::new(2, 2);

        let f = d + e;
    }
}
