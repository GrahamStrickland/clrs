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
        if self.rows == 1 && self.cols == 1 {
            writeln!(f, "\n[{}]", self.data[0])?;
        } else {
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
        }

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

impl<T> ops::Index<usize> for Matrix<T>
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
    type Output = [T];

    fn index(&self, i: usize) -> &[T] {
        &self.data[i * self.cols..i * self.cols + self.cols]
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

pub struct SquareMatrix<T>
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
    pub dimension: usize,
    data: Vec<T>,
}

impl<T> SquareMatrix<T>
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
    pub fn new(dimension: usize, data: Vec<Vec<T>>) -> SquareMatrix<T> {
        assert_eq!(data.len(), dimension);
        let mut new_data = vec![T::zero(); dimension * dimension];

        for row in 0..data.len() {
            assert_eq!(data[row].len(), dimension);
            for col in 0..dimension {
                new_data[row * dimension + col] = data[row][col];
            }
        }

        SquareMatrix {
            dimension,
            data: new_data,
        }
    }

    pub fn submatrix(&self, m: usize, n: usize) -> SquareMatrix<T> {
        assert!(self.dimension.is_multiple_of(2));
        let new_dimension = self.dimension / 2;
        assert!(m < new_dimension || new_dimension == 1);
        assert!(n < new_dimension || new_dimension == 1);

        let mut data = vec![T::zero(); new_dimension * new_dimension];
        for (p, row) in (0..new_dimension).zip(m * new_dimension..(m + 1) * new_dimension) {
            for (q, col) in (0..new_dimension).zip(n * new_dimension..(n + 1) * new_dimension) {
                data[p * new_dimension + q] = self.data[row * self.dimension + col];
            }
        }

        SquareMatrix {
            dimension: new_dimension,
            data,
        }
    }
}

impl<T> Clone for SquareMatrix<T>
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
    fn clone(&self) -> SquareMatrix<T> {
        SquareMatrix {
            dimension: self.dimension,
            data: self.data.clone(),
        }
    }
}

impl<T> Debug for SquareMatrix<T>
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
        if self.dimension == 1 {
            writeln!(f, "\n[{}]", self.data[0])?;
        } else {
            write!(f, "\n[")?;

            for row in 0..self.dimension {
                for col in 0..self.dimension {
                    if col == 0 {
                        write!(f, "[")?;
                    } else {
                        write!(f, ", ")?;
                    }
                    write!(f, "{}", self.data[row * self.dimension + col])?;
                }

                write!(f, "]")?;
                if row < self.dimension - 1 {
                    writeln!(f)?;
                }
            }
            writeln!(f)?;
        }

        FmtResult::Ok(())
    }
}

impl<T> PartialEq for SquareMatrix<T>
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
    fn eq(&self, _rhs: &SquareMatrix<T>) -> bool {
        if self.dimension != _rhs.dimension {
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

impl<T> ops::Index<usize> for SquareMatrix<T>
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
    type Output = [T];

    fn index(&self, i: usize) -> &[T] {
        &self.data[i * self.dimension..i * self.dimension + self.dimension]
    }
}

impl<T> ops::Add<SquareMatrix<T>> for SquareMatrix<T>
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
    type Output = SquareMatrix<T>;

    fn add(self, _rhs: SquareMatrix<T>) -> SquareMatrix<T> {
        assert_eq!(self.dimension, _rhs.dimension);

        let mut data = vec![T::zero(); self.dimension * self.dimension];
        for i in 0..self.data.len() {
            data[i] = self.data[i] + _rhs.data[i];
        }

        SquareMatrix {
            dimension: self.dimension,
            data,
        }
    }
}

impl<T> ops::Sub<SquareMatrix<T>> for SquareMatrix<T>
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
    type Output = SquareMatrix<T>;

    fn sub(self, _rhs: SquareMatrix<T>) -> SquareMatrix<T> {
        assert_eq!(self.dimension, _rhs.dimension);

        let mut data = vec![T::zero(); self.dimension * self.dimension];
        for i in 0..self.data.len() {
            data[i] = self.data[i] - _rhs.data[i];
        }

        SquareMatrix {
            dimension: self.dimension,
            data,
        }
    }
}

impl<T> ops::Mul<SquareMatrix<T>> for SquareMatrix<T>
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
    type Output = SquareMatrix<T>;

    fn mul(self, _rhs: SquareMatrix<T>) -> SquareMatrix<T> {
        assert_eq!(self.dimension, _rhs.dimension);

        let mut data = vec![T::zero(); self.dimension * _rhs.dimension];
        for i in 0..self.dimension {
            for j in 0.._rhs.dimension {
                let mut cij = T::zero();
                for k in 0..self.dimension {
                    cij = cij
                        + (self.data[i * self.dimension + k] * _rhs.data[k * _rhs.dimension + j]);
                }
                data[i * _rhs.dimension + j] = cij;
            }
        }

        SquareMatrix {
            dimension: self.dimension,
            data,
        }
    }
}
