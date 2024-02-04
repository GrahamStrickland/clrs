#ifndef MATRIX_H
#define MATRIX_H

#include <istream>
#include <ostream>
#include <stdexcept>
#include <string>

template <typename T>
class matrix {
public:
    matrix<T>(int row, int col);
    matrix<T>(const matrix<T> &src);
    matrix<T>(const std::initializer_list<std::initializer_list<T>>& list);
    ~matrix<T>();

    bool operator ==(const matrix<T> &src);
    matrix<T>& operator =(
            const std::initializer_list<std::initializer_list<T>>& list);
    matrix<T>& operator =(const matrix<T> &src);
    matrix<T> operator +(const matrix<T> &src) const;
    matrix<T> operator -(const matrix<T> &src) const;
    matrix<T> operator *(const matrix<T> &src) const;

    friend std::ostream& operator <<(std::ostream &outs, const matrix<T> &src) {
        outs << "\n[";
        for (int row = 0; row < src.m_rows; row++) {
            for (int col = 0; col < src.m_cols; col++) {
                outs << (col == 0 ? "[" : ", ") << src.m_data[row][col];
            }
            outs << "]" << (row == src.m_rows - 1 ? "" : ",\n");
        }
        outs << "]\n";

        return outs;
    }

private:
    int m_rows;
    int m_cols;
    T **m_data;
};

struct matrix_exception : public std::runtime_error {
    matrix_exception(const std::string& message = "Matrix exception") 
            : std::runtime_error(message) { }
};
#endif // MATRIX_H
