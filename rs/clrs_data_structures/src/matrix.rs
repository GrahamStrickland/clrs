use std::fmt::{Debug, Display, Formatter, Result as FmtResult};
use std::ops;

use num::traits::Zero;

pub struct Matrix<T>
where
    T: Zero
        + ops::Sub<Output = T>
        + ops::Mul<Output = T>
        + Sized
        + Clone
        + Copy
        + Display
        + PartialEq,
{
    pub rows: usize,
    pub cols: usize,
    data: Vec<T>,
}

impl<T> Matrix<T>
where
    T: Zero
        + ops::Sub<Output = T>
        + ops::Mul<Output = T>
        + Sized
        + Clone
        + Copy
        + Display
        + PartialEq,
{
    pub fn new(rows: usize, cols: usize, data: Vec<Vec<T>>) -> Matrix<T> {
        assert_eq!(data.len(), rows);
        let mut new_data = vec![T::zero(); rows * cols];

        for row in 0..data.len() {
            assert_eq!(data[row].len(), cols);
            for col in 0..cols {
                new_data[row * cols + col] = data[row][col];
            }
        }

        Matrix {
            rows,
            cols,
            data: new_data,
        }
    }
}

impl<T> Clone for Matrix<T>
where
    T: Zero
        + ops::Sub<Output = T>
        + ops::Mul<Output = T>
        + Sized
        + Clone
        + Copy
        + Display
        + PartialEq,
{
    fn clone(&self) -> Matrix<T> {
        Matrix {
            rows: self.rows,
            cols: self.cols,
            data: self.data.clone(),
        }
    }
}

impl<T> Debug for Matrix<T>
where
    T: Zero
        + ops::Sub<Output = T>
        + ops::Mul<Output = T>
        + Sized
        + Clone
        + Copy
        + Display
        + PartialEq,
{
    fn fmt(&self, f: &mut Formatter<'_>) -> FmtResult {
        write!(f, "\n[")?;
        for row in 0..self.rows {
            for col in 0..self.cols {
                if col == 0 {
                    write!(f, "[")?;
                } else {
                    write!(f, ", ")?;
                }
                write!(f, "{}", self.data[row * self.cols + col])?;
            }

            write!(f, "]")?;
            if row < self.rows - 1 {
                writeln!(f)?;
            }
        }
        writeln!(f)?;

        FmtResult::Ok(())
    }
}

impl<T> PartialEq for Matrix<T>
where
    T: Zero
        + ops::Sub<Output = T>
        + ops::Mul<Output = T>
        + Sized
        + Clone
        + Copy
        + Display
        + PartialEq,
{
    fn eq(&self, _rhs: &Matrix<T>) -> bool {
        if self.rows != _rhs.rows || self.cols != _rhs.cols {
            return false;
        }

        for i in 0..self.data.len() {
            if self.data[i] != _rhs.data[i] {
                return false;
            }
        }

        true
    }
}

impl<T> ops::Add<Matrix<T>> for Matrix<T>
where
    T: Zero
        + ops::Sub<Output = T>
        + ops::Mul<Output = T>
        + Sized
        + Clone
        + Copy
        + Display
        + PartialEq,
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
            data,
        }
    }
}

impl<T> ops::Sub<Matrix<T>> for Matrix<T>
where
    T: Zero
        + ops::Sub<Output = T>
        + ops::Mul<Output = T>
        + Sized
        + Clone
        + Copy
        + Display
        + PartialEq,
{
    type Output = Matrix<T>;

    fn sub(self, _rhs: Matrix<T>) -> Matrix<T> {
        assert_eq!(self.rows, _rhs.rows);
        assert_eq!(self.cols, _rhs.cols);

        let mut data = vec![T::zero(); self.rows * self.cols];
        for i in 0..self.data.len() {
            data[i] = self.data[i] - _rhs.data[i];
        }

        Matrix {
            rows: self.rows,
            cols: self.cols,
            data,
        }
    }
}

impl<T> ops::Mul<Matrix<T>> for Matrix<T>
where
    T: Zero
        + ops::Sub<Output = T>
        + ops::Mul<Output = T>
        + Sized
        + Clone
        + Copy
        + Display
        + PartialEq,
{
    type Output = Matrix<T>;

    fn mul(self, _rhs: Matrix<T>) -> Matrix<T> {
        assert_eq!(self.cols, _rhs.rows);

        let mut data = vec![T::zero(); self.rows * _rhs.cols];
        for i in 0..self.rows {
            for j in 0.._rhs.cols {
                let mut cij = T::zero();
                for k in 0..self.cols {
                    cij = cij + (self.data[i * self.cols + k] * _rhs.data[k * _rhs.cols + j]);
                }
                data[i * _rhs.cols + j] = cij;
            }
        }

        Matrix {
            rows: self.rows,
            cols: _rhs.cols,
            data,
        }
    }
}
