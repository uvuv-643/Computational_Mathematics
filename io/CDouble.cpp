//
// Created by artem on 10.02.2023.
//

#pragma once
#include "CDouble.h"

ostream &operator<<(ostream &os, const CDouble &validated) {
    os << setprecision(8);
    os << validated.value;
    return os;
}

istream &operator>>(istream &is, CDouble &data) {
    double inputted; string val;
    if (&is == &cin) {
        cerr << "Input double:" << endl;
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

CDouble::CDouble() {
    this->value = 0;
}

CDouble::CDouble(double _value) {
    this->value = _value;
}

CDouble operator+(CDouble lhs, const CDouble &rhs) {
    lhs += rhs;
    return lhs;
}

CDouble &CDouble::operator+=(const CDouble &rhs) {
    this->value += rhs.value;
    return *this;
}
