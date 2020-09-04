//
// Created by GOFORBROKE on 04.09.2020.
//

#ifndef MATH_MATRIX_H
#define MATH_MATRIX_H

#include <type_traits>
#include <vector>
#include <stdexcept>

template<typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type * = nullptr>
class Matrix {
public:
    Matrix(int rows, int cols) : rowsCount(rows), colsCount(cols) {
        items.resize(rows * cols);
    }

    void Set(std::vector<T> vector) {
        if (rowsCount * colsCount != vector.size()) {
            throw std::logic_error("wrong items sequence size");
        }
        this->items = vector;
    }

    T At(int ri, int ci) const {
        if (ri >= rowsCount || ci >= colsCount)
            throw std::logic_error("wrong position");
        return items[ri * colsCount + ci];
    }

    T &At(int ri, int ci) {
        if (ri >= rowsCount || ci >= colsCount)
            throw std::logic_error("wrong position");
        return items[ri * colsCount + ci];
    }

    int GetRowsCount() const {
        return rowsCount;
    }

    int GetColsCount() const {
        return colsCount;
    }

    Matrix<T> operator*(const Matrix<T> &rhs) const {
        if (colsCount != rhs.rowsCount) {
            throw std::logic_error("rows count in matrix A should be equal to columns count in matrix B");
        }

        int resultRowsCount = this->rowsCount;
        int resultColsCount = rhs.colsCount;

        auto result = Matrix<T>(resultRowsCount, resultColsCount);

        for (int resRI = 0; resRI < resultRowsCount; ++resRI) {
            for (int resCI = 0; resCI < resultColsCount; ++resCI) {

                T sum = 0;

                {
                    for (int k = 0; k < colsCount; ++k) {
                        sum += (At(resRI, k) * rhs.At(k, resCI));
                    }
                }

                result.At(resRI, resCI) = sum;

            }
        }

        return result;
    }

    bool operator==(const Matrix<T> &rhs) const {
        if (rowsCount != rhs.rowsCount || colsCount != rhs.colsCount) return false;

        for (int ri = 0; ri < GetRowsCount(); ++ri) {
            for (int ci = 0; ci < GetColsCount(); ++ci) {
                if (At(ri, ci) != rhs.At(ri, ci)) return false;
            }
        }

        return true;
    }

    bool operator!=(const Matrix<T> &rhs) const {
        return !this->operator==(rhs);
    }

private:
    std::vector<T> items;
    int rowsCount, colsCount;
};

#include <iostream>

template<typename T>
std::ostream &operator<<(std::ostream &ostream, const Matrix<T> &matrix) {
    for (int ri = 0; ri < matrix.GetRowsCount(); ++ri) {
        for (int ci = 0; ci < matrix.GetColsCount(); ++ci) {
            ostream << matrix.At(ri, ci) << " ";
        }
        ostream << std::endl;
    }
    return ostream;
}


#endif //MATH_MATRIX_H
