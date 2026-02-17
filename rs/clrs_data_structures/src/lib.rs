pub mod matrix;

#[cfg(test)]
mod tests {
    // Matrix tests
    use super::matrix::Matrix;

    #[test]
    fn test_matrix_eq() {
        let a: Matrix<i32> = Matrix::new(3, 3, vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]]);
        let mut b = a.clone();

        assert_eq!(a, b);

        b = Matrix::new(3, 3, vec![vec![1, 1, 1], vec![1, 1, 1], vec![1, 1, 1]]);
        assert_ne!(a, b);
    }

    #[test]
    fn test_matrix_add() {
        let a: Matrix<i32> = Matrix::new(3, 3, vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]]);
        let b: Matrix<i32> =
            Matrix::new(3, 3, vec![vec![1, -1, 1], vec![-1, 1, -1], vec![1, -1, 1]]);

        let c = a + b;
        assert_eq!(
            c,
            Matrix::new(3, 3, vec![vec![2, 1, 4], vec![3, 6, 5], vec![8, 7, 10]])
        );
    }

    #[test]
    fn test_matrix_sub() {
        let a: Matrix<i32> = Matrix::new(3, 3, vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]]);
        let b: Matrix<i32> =
            Matrix::new(3, 3, vec![vec![1, -1, 1], vec![-1, 1, -1], vec![1, -1, 1]]);
        let c = a - b;
        assert_eq!(
            c,
            Matrix::new(3, 3, vec![vec![0, 3, 2], vec![5, 4, 7], vec![6, 9, 8]])
        );
    }

    #[test]
    fn test_matrix_mul() {
        let a: Matrix<i32> = Matrix::new(3, 3, vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]]);
        let b: Matrix<i32> =
            Matrix::new(3, 3, vec![vec![1, -1, 1], vec![-1, 1, -1], vec![1, -1, 1]]);
        let c = a * b;
        assert_eq!(
            c,
            Matrix::new(3, 3, vec![vec![2, -2, 2], vec![5, -5, 5], vec![8, -8, 8]])
        );

        let d: Matrix<f64> = Matrix::new(2, 3, vec![vec![0.25, 0.0, 0.0], vec![0.0, 0.25, 0.0]]);
        let e: Matrix<f64> =
            Matrix::new(3, 2, vec![vec![0.0, -3.0], vec![-3.0, 0.0], vec![0.0, 1.0]]);
        let f = d * e;
        assert_eq!(
            f,
            Matrix::new(2, 2, vec![vec![0.0, -0.75], vec![-0.75, 0.0]])
        );
    }
}
