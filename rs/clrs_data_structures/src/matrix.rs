use std::fmt::{Debug, Display, Formatter, Result as FmtResult};
use std::ops;

use num::traits::Zero;

pub trait MatrixElement:
    Zero
    + ops::Add<Output = Self>
    + ops::Sub<Output = Self>
    + ops::Mul<Output = Self>
    + Sized
    + Clone
    + Copy
    + Display
    + PartialEq
{
}

impl<T> MatrixElement for T where
    T: Zero
        + ops::Add<Output = Self>
        + ops::Sub<Output = Self>
        + ops::Mul<Output = Self>
        + Sized
        + Clone
        + Copy
        + Display
        + PartialEq
{
}

pub struct Matrix<T>
where
    T: MatrixElement,
{
    pub rows: usize,
    pub cols: usize,
    data: Vec<T>,
}

impl<T> Matrix<T>
where
    T: MatrixElement,
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
    T: MatrixElement,
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
    T: MatrixElement,
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
    T: MatrixElement,
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
    T: MatrixElement,
{
    type Output = [T];

    fn index(&self, i: usize) -> &[T] {
        &self.data[i * self.cols..i * self.cols + self.cols]
    }
}

impl<T> ops::Add<Matrix<T>> for Matrix<T>
where
    T: MatrixElement,
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
    T: MatrixElement,
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
    T: MatrixElement,
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
    T: MatrixElement,
{
    pub dimension: usize,
    data: Vec<T>,
}

impl<T> SquareMatrix<T>
where
    T: MatrixElement,
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
        if self.dimension == 1 {
            assert!(m == 0);
            assert!(n == 0);
            return self.clone();
        }

        let new_dimension = self.dimension / 2;
        assert!(m <= 1);
        assert!(n <= 1);

        let mut data = vec![T::zero(); new_dimension * new_dimension];
        for row in 0..new_dimension {
            for col in 0..new_dimension {
                let self_row = m * new_dimension + row;
                let self_col = n * new_dimension + col;
                data[row * new_dimension + col] = self.data[self_row * self.dimension + self_col];
            }
        }

        SquareMatrix {
            dimension: new_dimension,
            data,
        }
    }

    // 3. Refactored assign_submatrix to take SquareMatrix<T>
    pub fn assign_submatrix(&mut self, m: usize, n: usize, rhs: SquareMatrix<T>) {
        assert!(self.dimension % 2 == 0);
        let new_dimension = self.dimension / 2;
        assert!(m <= 1 || new_dimension == 1);
        assert!(n <= 1 || new_dimension == 1);

        for row in 0..new_dimension {
            for col in 0..new_dimension {
                let self_row = m * new_dimension + row;
                let self_col = n * new_dimension + col;
                self.data[self_row * self.dimension + self_col] =
                    rhs.data[row * new_dimension + col];
            }
        }
    }

    pub fn multiply_recursive(self, rhs: SquareMatrix<T>) -> SquareMatrix<T> {
        let mut result = SquareMatrix {
            dimension: self.dimension,
            data: vec![T::zero(); self.dimension * self.dimension],
        };

        if self.dimension == 1 {
            result.data[0] = self.data[0] * rhs.data[0];
            return result;
        }

        let a11 = self.submatrix(0, 0);
        let a12 = self.submatrix(0, 1);
        let a21 = self.submatrix(1, 0);
        let a22 = self.submatrix(1, 1);

        let b11 = rhs.submatrix(0, 0);
        let b12 = rhs.submatrix(0, 1);
        let b21 = rhs.submatrix(1, 0);
        let b22 = rhs.submatrix(1, 1);

        let c11 = a11.clone().multiply_recursive(b11.clone())
            + a12.clone().multiply_recursive(b21.clone());
        let c12 = a11.clone().multiply_recursive(b12.clone())
            + a12.clone().multiply_recursive(b22.clone());
        let c21 = a21.clone().multiply_recursive(b11) + a22.clone().multiply_recursive(b21);
        let c22 = a21.multiply_recursive(b12) + a22.multiply_recursive(b22);

        result.assign_submatrix(0, 0, c11);
        result.assign_submatrix(0, 1, c12);
        result.assign_submatrix(1, 0, c21);
        result.assign_submatrix(1, 1, c22);

        result
    }

    pub fn strassen_multiply(self, rhs: SquareMatrix<T>) -> SquareMatrix<T> {
        let mut result = SquareMatrix {
            dimension: self.dimension,
            data: vec![T::zero(); self.dimension * self.dimension],
        };

        if self.dimension == 1 {
            result.data[0] = self.data[0] * rhs.data[0];
            return result;
        }

        let a11 = self.submatrix(0, 0);
        let a12 = self.submatrix(0, 1);
        let a21 = self.submatrix(1, 0);
        let a22 = self.submatrix(1, 1);

        let b11 = rhs.submatrix(0, 0);
        let b12 = rhs.submatrix(0, 1);
        let b21 = rhs.submatrix(1, 0);
        let b22 = rhs.submatrix(1, 1);

        let s1 = b12.clone() - b22.clone();
        let s2 = a11.clone() + a12.clone();
        let s3 = a21.clone() + a22.clone();
        let s4 = b21.clone() - b11.clone();
        let s5 = a11.clone() + a22.clone();
        let s6 = b11.clone() + b22.clone();
        let s7 = a12.clone() - a22.clone();
        let s8 = b21.clone() + b22.clone();
        let s9 = a11.clone() - a21.clone();
        let s10 = b11.clone() + b12.clone();

        let p1 = a11.strassen_multiply(s1);
        let p2 = s2.strassen_multiply(b22);
        let p3 = s3.strassen_multiply(b11);
        let p4 = a22.strassen_multiply(s4);
        let p5 = s5.strassen_multiply(s6);
        let p6 = s7.strassen_multiply(s8);
        let p7 = s9.strassen_multiply(s10);

        let c11 = p5.clone() + p4.clone() - p2.clone() + p6;
        let c12 = p1.clone() + p2;
        let c21 = p3.clone() + p4;
        let c22 = p5 + p1 - p3 - p7;

        result.assign_submatrix(0, 0, c11);
        result.assign_submatrix(0, 1, c12);
        result.assign_submatrix(1, 0, c21);
        result.assign_submatrix(1, 1, c22);

        result
    }
}

impl<T> Clone for SquareMatrix<T>
where
    T: MatrixElement,
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
    T: MatrixElement,
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
    T: MatrixElement,
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
    T: MatrixElement,
{
    type Output = [T];

    fn index(&self, i: usize) -> &[T] {
        &self.data[i * self.dimension..i * self.dimension + self.dimension]
    }
}

impl<T> ops::Add<SquareMatrix<T>> for SquareMatrix<T>
where
    T: MatrixElement,
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
    T: MatrixElement,
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
    T: MatrixElement,
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
