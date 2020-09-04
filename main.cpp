#include <iostream>

#include "Matrix.h"
#include "Vector.h"
#include "operations.h"

int main() {
    {
        auto m = Matrix<int>(3, 3);
        m.Set({
                      2, 4, 0,
                      -2, 1, 3,
                      -1, 0, 1,
              });
        auto v = Vector<int>({1, 2, -1});

        auto actual = v * m;
        auto expected = Vector<int>({10, -3, -2});

        if (actual != expected) {
            std::cout << "Failed!!";
        } else {
            std::cout << "At last...";
        }
        std::cout << std::endl;
    }

    {
        auto a = Matrix<int>(4, 1);
        a.Set({
                      3,
                      2,
                      0,
                      1
              });
        auto b = Matrix<int>(1, 4);
        b.Set({
                      -1, 1, 0, 2,
              });

        auto actual = a * b;
        auto expected = Matrix<int>(4, 4);
        expected.Set({
                             -3, 3, 0, 6,
                             -2, 2, 0, 4,
                             0, 0, 0, 0,
                             -1, 1, 0, 2,
                     });
        if (actual != expected) {
            std::cout << "Failed!!" << std::endl;

            std::cout << actual << std::endl << expected << std::endl;
        } else {
            std::cout << "At last...";
        }
        std::cout << std::endl;
    }

    {
        auto a = Matrix<int>(2, 3);
        a.Set({
                      2, -3, 1,
                      5, 4, -2,
              });
        auto b = Matrix<int>(3, 2);
        b.Set({
                      -7, 5,
                      2, -1,
                      4, 3,
              });

        auto actual = a * b;
        auto expected = Matrix<int>(2, 2);
        expected.Set({
                             -16, 16,
                             -35, 15,
                     });
        if (actual != expected) {
            std::cout << "Failed!!" << std::endl;

            std::cout << actual << std::endl << expected << std::endl;
        } else {
            std::cout << "At last...";
        }
        std::cout << std::endl;
    }

    return 0;
}
