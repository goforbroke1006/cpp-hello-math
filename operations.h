//
// Created by GOFORBROKE on 04.09.2020.
//

#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

#include <stdexcept>

#include "Vector.h"
#include "Matrix.h"

template<typename T>
Vector<T> operator*(const Vector<T> &v, const Matrix<T> &m) {
    if (v.Length() != m.GetCols()) {
        throw std::logic_error("unsuitable vector for matrix");
    }

    auto result = Vector<T>(v.Length());
    int resCounter = 0;

    for (int ri = 0; ri < m.GetRows(); ++ri) {
        T sum = 0;
        for (int ci = 0; ci < m.GetCols(); ++ci) {
            const T &mi = m.At(ri, ci);
            const T &vi = v.At(ci);
            sum += (mi * vi);
        }
        result.At(resCounter++) = sum;
    }

    return result;
}

#endif //MATH_OPERATIONS_H
