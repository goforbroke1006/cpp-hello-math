//
// Created by GOFORBROKE on 07.09.2020.
//

#ifndef CPP_HELLO_MATH_LINEAR_TRANSFORMATION_H
#define CPP_HELLO_MATH_LINEAR_TRANSFORMATION_H

#include <stdexcept>

#include "Vector.h"
#include "Matrix.h"
#include "operations.h"

Vector<double> scale(
        const Vector<double> &point,
        double scaleX = 1, double scaleY = 1, double scaleZ = 1
) {
    if (point.Length() != 3) {
        throw std::logic_error("wrong point coordinates - is not 3D coordinates");
    }

    auto scaleMatrix = Matrix<double>(3, 3);
    scaleMatrix.Set({
                            scaleX, 0, 0,
                            0, scaleY, 0,
                            0, 0, scaleZ,
                    });
    Vector<double> result = point * scaleMatrix;
    return result;
}

#endif //CPP_HELLO_MATH_LINEAR_TRANSFORMATION_H
