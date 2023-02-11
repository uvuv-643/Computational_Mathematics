//
// Created by artem on 10.02.2023.
//

#include "CFloat.h"
#include <iomanip>

ostream &operator<<(ostream &os, const CFloat &validated) {
    os << fixed;
    os << setprecision(3);
    os << validated.value;
    return os;
}

istream &operator>>(istream &is, CFloat &data) {
    float inputted;
    if (std::getenv("DEBUG_MODE")) {
        cerr << "Input float:" << endl;
    }
    while (!(is >> inputted)) {
        cin.clear();
        cin.ignore(1000, '\n');
        if (std::getenv("DEBUG_MODE")) {
            cerr << "Wrong input" << endl;
        }
    }
    data.value = inputted;
    return is;
}

CFloat::CFloat() {
    this->value = 0;
}

CFloat::CFloat(float _value) {
    this->value = _value;
}

CFloat operator+(CFloat lhs, const CFloat &rhs) {
    lhs += rhs;
    return lhs;
}

CFloat &CFloat::operator+=(const CFloat &rhs) {
    this->value += rhs.value;
    return *this;
}
