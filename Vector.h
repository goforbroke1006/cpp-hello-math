//
// Created by GOFORBROKE on 04.09.2020.
//

#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

#include <vector>
#include <type_traits>
#include <cstring>

template<typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type * = nullptr>
class Vector {
public:
    Vector(size_t vs) {
        items.resize(vs);
    }

    Vector(std::vector<T> numbers) {
        items = numbers;
    }

    T At(int index) const {
        return items[index];
    }

    T &At(int index) {
        return items.at(index);
    }

    int Length() const {
        return items.size();
    }

    bool operator==(const Vector<T> rh) const {
        if (items.size() != rh.items.size()) return false;
        for (int index = 0; index < items.size(); ++index) {
            if (items[index] != rh.items[index]) return false;
        }
        return true;
    }

    bool operator!=(const Vector<T> rh) const {
        return !this->operator==(rh);
    }

private:
    std::vector<T> items;
};


#endif //MATH_VECTOR_H
