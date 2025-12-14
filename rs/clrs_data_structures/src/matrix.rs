use std::ops;

use num::traits::Zero;

pub struct Matrix<T>
where
    T: Zero + Sized + Clone + Copy,
{
    rows: usize,
    cols: usize,
    data: Vec<T>,
}

impl<T> Matrix<T>
where
    T: Zero + Sized + Clone + Copy,
{
    pub fn new(cols: usize, rows: usize) -> Matrix<T> {
        Matrix {
            rows: rows,
            cols: cols,
            data: vec![T::zero(); rows * cols],
        }
    }
}

impl<T> ops::Add<Matrix<T>> for Matrix<T>
where
    T: Zero + Sized + Clone + Copy,
{
    type Output = Matrix<T>;

    fn add(self, _rhs: Matrix<T>) -> Matrix<T> {
        assert_eq!(self.rows, _rhs.rows);
        assert_eq!(self.cols, _rhs.cols);

        let mut data = vec![T::zero(); self.rows * self.cols];
        for i in 0..self.data.len() {
            data[i] = self.data[i] + _rhs.data[i];
        }

        Matrix {
            rows: self.rows,
            cols: self.cols,
            data: data,
        }
    }
}
