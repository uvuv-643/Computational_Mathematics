//
// Created by artem on 10.02.2023.
//

#pragma once
#include "CFloat.h"

ostream &operator<<(ostream &os, const CFloat &validated) {
    os << setprecision(8);
    os << validated.value;
    return os;
}

istream &operator>>(istream &is, CFloat &data) {
    float inputted; string val;
    if (&is == &cin) {
        cerr << "Input float:" << endl;
    }
    while (true) {
        is >> val;
        try {
            std::replace( val.begin(), val.end(), ',', '.');
            inputted = stof(val);
            break;
        } catch (const std::invalid_argument& ignored) { }
        if (&is == &cin) {
            cerr << "Wrong input" << endl;
            is.clear();
            is.ignore(1000, '\n');
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
