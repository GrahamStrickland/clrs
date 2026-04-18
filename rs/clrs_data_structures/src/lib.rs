pub mod matrix;

#[cfg(test)]
mod tests {
    // Matrix tests
    use super::matrix::Matrix;

    #[test]
    fn test_matrix_index() {
        let a: Matrix<i32> = Matrix::new(3, 3, vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]]);

        assert_eq!(a[0][0], 1);
        assert_eq!(a[0][1], 2);
        assert_eq!(a[0][2], 3);
        assert_eq!(a[1][0], 4);
        assert_eq!(a[1][1], 5);
        assert_eq!(a[1][2], 6);
        assert_eq!(a[2][0], 7);
        assert_eq!(a[2][1], 8);
        assert_eq!(a[2][2], 9);
    }

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

    // Square matrix tests
    use super::matrix::SquareMatrix;

    #[test]
    fn test_square_matrix_index() {
        let a: SquareMatrix<i32> =
            SquareMatrix::new(3, vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]]);

        assert_eq!(a[0][0], 1);
        assert_eq!(a[0][1], 2);
        assert_eq!(a[0][2], 3);
        assert_eq!(a[1][0], 4);
        assert_eq!(a[1][1], 5);
        assert_eq!(a[1][2], 6);
        assert_eq!(a[2][0], 7);
        assert_eq!(a[2][1], 8);
        assert_eq!(a[2][2], 9);
    }

    #[test]
    fn test_square_matrix_submatrix() {
        let a: SquareMatrix<i32> = SquareMatrix::new(2, vec![vec![1, 2], vec![3, 4]]);

        assert_eq!(a.submatrix(0, 0), SquareMatrix::new(1, vec![vec![1]]));
        assert_eq!(a.submatrix(0, 1), SquareMatrix::new(1, vec![vec![2]]));
        assert_eq!(a.submatrix(1, 0), SquareMatrix::new(1, vec![vec![3]]));
        assert_eq!(a.submatrix(1, 1), SquareMatrix::new(1, vec![vec![4]]));

        let b: SquareMatrix<i32> = SquareMatrix::new(
            4,
            vec![
                vec![1, 2, 3, 4],
                vec![5, 6, 7, 8],
                vec![9, 10, 11, 12],
                vec![13, 14, 15, 16],
            ],
        );

        assert_eq!(
            b.submatrix(0, 0),
            SquareMatrix::new(2, vec![vec![1, 2], vec![5, 6]])
        );
        assert_eq!(
            b.submatrix(0, 1),
            SquareMatrix::new(2, vec![vec![3, 4], vec![7, 8]])
        );
        assert_eq!(
            b.submatrix(1, 0),
            SquareMatrix::new(2, vec![vec![9, 10], vec![13, 14]])
        );
        assert_eq!(
            b.submatrix(1, 1),
            SquareMatrix::new(2, vec![vec![11, 12], vec![15, 16]])
        );
    }

    #[test]
    fn test_square_matrix_assign_submatrix() {
        let mut a: SquareMatrix<i32> = SquareMatrix::new(2, vec![vec![0, 0], vec![0, 0]]);

        a.assign_submatrix(0, 0, SquareMatrix::new(1, vec![vec![1]]));
        a.assign_submatrix(0, 1, SquareMatrix::new(1, vec![vec![2]]));
        a.assign_submatrix(1, 0, SquareMatrix::new(1, vec![vec![3]]));
        a.assign_submatrix(1, 1, SquareMatrix::new(1, vec![vec![4]]));

        assert_eq!(a.submatrix(0, 0), SquareMatrix::new(1, vec![vec![1]]));
        assert_eq!(a.submatrix(0, 1), SquareMatrix::new(1, vec![vec![2]]));
        assert_eq!(a.submatrix(1, 0), SquareMatrix::new(1, vec![vec![3]]));
        assert_eq!(a.submatrix(1, 1), SquareMatrix::new(1, vec![vec![4]]));

        let mut b: SquareMatrix<i32> = SquareMatrix::new(
            4,
            vec![
                vec![0, 0, 0, 0],
                vec![0, 0, 0, 0],
                vec![0, 0, 0, 0],
                vec![0, 0, 0, 0],
            ],
        );

        b.assign_submatrix(0, 0, SquareMatrix::new(2, vec![vec![1, 2], vec![5, 6]]));
        b.assign_submatrix(0, 1, SquareMatrix::new(2, vec![vec![3, 4], vec![7, 8]]));
        b.assign_submatrix(1, 0, SquareMatrix::new(2, vec![vec![9, 10], vec![13, 14]]));
        b.assign_submatrix(1, 1, SquareMatrix::new(2, vec![vec![11, 12], vec![15, 16]]));

        assert_eq!(
            b.submatrix(0, 0),
            SquareMatrix::new(2, vec![vec![1, 2], vec![5, 6]])
        );
        assert_eq!(
            b.submatrix(0, 1),
            SquareMatrix::new(2, vec![vec![3, 4], vec![7, 8]])
        );
        assert_eq!(
            b.submatrix(1, 0),
            SquareMatrix::new(2, vec![vec![9, 10], vec![13, 14]])
        );
        assert_eq!(
            b.submatrix(1, 1),
            SquareMatrix::new(2, vec![vec![11, 12], vec![15, 16]])
        );
    }

    #[test]
    fn test_multiply_recursive() {
        let a: SquareMatrix<i32> = SquareMatrix::new(
            2,
            vec![
                vec![1, 3],
                vec![7, 5],
            ],
        );
        let b: SquareMatrix<i32> = SquareMatrix::new(
            2,
            vec![
                vec![6, 8],
                vec![4, 2],
            ],
        );
        let c = a.multiply_recursive(b);
        assert_eq!(
            c,
            SquareMatrix::new(
                2,
                vec![
                    vec![18, 14],
                    vec![62, 66],
                ]
            )
        );

        let d: SquareMatrix<i32> = SquareMatrix::new(
            4,
            vec![
                vec![1, 2, 3, 4],
                vec![5, 6, 7, 8],
                vec![9, 10, 11, 12],
                vec![13, 14, 15, 16],
            ],
        );
        let e: SquareMatrix<i32> = SquareMatrix::new(
            4,
            vec![
                vec![1, -1, 1, -1],
                vec![-1, 1, -1, 1],
                vec![1, -1, 1, -1],
                vec![-1, 1, -1, 1],
            ],
        );
        let f = d.multiply_recursive(e);
        assert_eq!(
            f,
            SquareMatrix::new(
                4,
                vec![
                    vec![-2, 2, -2, 2],
                    vec![-2, 2, -2, 2],
                    vec![-2, 2, -2, 2],
                    vec![-2, 2, -2, 2]
                ]
            )
        );
    }

    #[test]
    fn test_square_matrix_strassen_multiply() {
        let a: SquareMatrix<i32> = SquareMatrix::new(
            2,
            vec![
                vec![1, 3],
                vec![7, 5],
            ],
        );
        let b: SquareMatrix<i32> = SquareMatrix::new(
            2,
            vec![
                vec![6, 8],
                vec![4, 2],
            ],
        );
        let c = a.strassen_multiply(b);
        assert_eq!(
            c,
            SquareMatrix::new(
                2,
                vec![
                    vec![18, 14],
                    vec![62, 66],
                ]
            )
        );

        let d: SquareMatrix<i32> = SquareMatrix::new(
            4,
            vec![
                vec![1, 2, 3, 4],
                vec![5, 6, 7, 8],
                vec![9, 10, 11, 12],
                vec![13, 14, 15, 16],
            ],
        );
        let e: SquareMatrix<i32> = SquareMatrix::new(
            4,
            vec![
                vec![1, -1, 1, -1],
                vec![-1, 1, -1, 1],
                vec![1, -1, 1, -1],
                vec![-1, 1, -1, 1],
            ],
        );
        let f = d.strassen_multiply(e);
        assert_eq!(
            f,
            SquareMatrix::new(
                4,
                vec![
                    vec![-2, 2, -2, 2],
                    vec![-2, 2, -2, 2],
                    vec![-2, 2, -2, 2],
                    vec![-2, 2, -2, 2]
                ]
            )
        );
    }

    #[test]
    fn test_square_matrix_eq() {
        let a: SquareMatrix<i32> =
            SquareMatrix::new(3, vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]]);
        let mut b = a.clone();

        assert_eq!(a, b);

        b = SquareMatrix::new(3, vec![vec![1, 1, 1], vec![1, 1, 1], vec![1, 1, 1]]);
        assert_ne!(a, b);
    }

    #[test]
    fn test_square_matrix_add() {
        let a: SquareMatrix<i32> =
            SquareMatrix::new(3, vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]]);
        let b: SquareMatrix<i32> =
            SquareMatrix::new(3, vec![vec![1, -1, 1], vec![-1, 1, -1], vec![1, -1, 1]]);

        let c = a + b;
        assert_eq!(
            c,
            SquareMatrix::new(3, vec![vec![2, 1, 4], vec![3, 6, 5], vec![8, 7, 10]])
        );
    }

    #[test]
    fn test_square_matrix_sub() {
        let a: SquareMatrix<i32> =
            SquareMatrix::new(3, vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]]);
        let b: SquareMatrix<i32> =
            SquareMatrix::new(3, vec![vec![1, -1, 1], vec![-1, 1, -1], vec![1, -1, 1]]);
        let c = a - b;
        assert_eq!(
            c,
            SquareMatrix::new(3, vec![vec![0, 3, 2], vec![5, 4, 7], vec![6, 9, 8]])
        );
    }

    #[test]
    fn test_square_matrix_mul() {
        let a: SquareMatrix<i32> =
            SquareMatrix::new(3, vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]]);
        let b: SquareMatrix<i32> =
            SquareMatrix::new(3, vec![vec![1, -1, 1], vec![-1, 1, -1], vec![1, -1, 1]]);
        let c = a * b;
        assert_eq!(
            c,
            SquareMatrix::new(3, vec![vec![2, -2, 2], vec![5, -5, 5], vec![8, -8, 8]])
        );
    }
}
