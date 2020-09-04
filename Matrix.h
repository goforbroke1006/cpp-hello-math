//
// Created by GOFORBROKE on 04.09.2020.
//

#ifndef MATH_MATRIX_H
#define MATH_MATRIX_H

#include <vector>
#include  <stdexcept>
#include <type_traits>

template<typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type * = nullptr>
class Matrix {
public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        items.resize(rows * cols);
    }

    void Set(std::vector<T> vector) {
        if (rows * cols != vector.size()) {
            throw std::logic_error("wrong items sequence size");
        }
        this->items = vector;
    }

    T At(int ri, int ci) const {
        return items[ri * cols + ci];
    }

    T &At(int ri, int ci) {
        return items[ri * cols + ci];
    }

    int GetRows() const {
        return rows;
    }

    int GetCols() const {
        return cols;
    }

    Matrix<T> operator*(const Matrix<T> rhs) const {
        int rrows = this->rows;
        int rcols = rhs.cols;
        auto result = Matrix<T>(rrows, rcols);
        // TODO:
        return result;
    }

    bool operator==(const Matrix<T> rhs) const {
        if (rows != rhs.rows || cols != rhs.cols) return false;

        for (int ri = 0; ri < GetRows(); ++ri) {
            for (int ci = 0; ci < GetCols(); ++ci) {
                if (At(ri, ci) != rhs.At(ri, ci)) return false;
            }
        }

        return true;
    }

    bool operator!=(const Matrix<T> rhs) const {
        return !this->operator==(rhs);
    }

private:
    std::vector<T> items;
    int rows, cols;
};


#endif //MATH_MATRIX_H
