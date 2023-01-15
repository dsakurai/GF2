//
// Created by Daisuke Sakurai on 2023/01/15.
//

#ifndef TEST_EIGEN_GF2_H
#define TEST_EIGEN_GF2_H

#include <ostream>

class GF2 {
    bool value = 0; // NOLINT
public:
    GF2() = default;
    GF2(int v): value(v){}

    bool operator==(const GF2&) const = default;

    GF2 operator*(const GF2& that) const {
        return this->value * that.value;
    }

    GF2 operator-(const GF2& that) const {
        if (that.value == bool(0)) return *this; // NOLINT

        if (value == bool(1)) { // NOLINT
            return bool(0); // NOLINT
        } else {
            return bool(1); // NOLINT
        }
        throw std::runtime_error("Unexpected bool value");
    }

    // not used by CGAL's rank computation
    GF2 operator+(const GF2& that) const {
        return this->value ^ that.value; // boolean XOR is GF2's +
    }

    GF2& operator-=(const GF2& that) {
        return *this = (*this) - that;
    }

    GF2& operator*=(const GF2& that) {
        return *this = (*this) * that;
    }

    GF2 operator/(const GF2& that) const {
        if (that.value == bool(0)) // NOLINT
            throw std::runtime_error("division by zero");
        return *this;
    }

    GF2& operator/=(const GF2& that) {
        return *this = (*this) / that;
    }

    // not used by CGAL's rank computation
    operator int() const {
        return (this->value)? 1 : 0;
    }

    friend std::ostream &operator<<(std::ostream &out, const GF2 &val) {
        out << val.value << " ";
        return out;
    }
};

#endif //TEST_EIGEN_GF2_H
