//
// Created by artem on 10.02.2023.
//

#pragma once
#include "CInt.h"

ostream &operator<<(ostream &os, const CInt &validated) {
    os << validated.value;
    return os;
}

istream &operator>>(istream &is, CInt &data) {
    int32_t inputted;
    if (&is == &cin) {
        cerr << "Input int:" << endl;
    }
    while (!(is >> inputted) && !is.eof()) {
        is.clear();
        is.ignore(1000, '\n');
        if (std::getenv("DEBUG_MODE")) {
            cerr << "Wrong input" << endl;
        }
    }
    data.value = inputted;
    return is;
}

CInt::CInt() {
    this->value = 0;
}

CInt::CInt(int _value) {
    this->value = _value;
}

CInt operator+(CInt lhs, const CInt &rhs) {
    lhs += rhs;
    return lhs;
}
CInt operator+(CInt lhs, const int &rhs) {
    lhs += rhs;
    return lhs;
}

CInt &CInt::operator+=(const CInt &rhs) {
    this->value += rhs.value;
    return *this;
}
CInt &CInt::operator+=(const int &rhs) {
    this->value += rhs;
    return *this;
}

const CInt operator++(CInt &i, int) {
    CInt oldValue(i.value);
    i.value++;
    return oldValue;
}

bool operator==(CInt c1, CInt c2) {
    return c1.value == c2.value;
}

bool operator!=(CInt c1, CInt c2) {
    return c1.value != c2.value;
}

bool operator>(CInt c1, CInt c2) {
    return c1.value > c2.value;
}

bool operator<(CInt c1, CInt c2) {
    return c1.value < c2.value;
}

bool operator==(CInt c1, int c2) {
    return c1.value == c2;
}

bool operator!=(CInt c1, int c2) {
    return c1.value != c2;
}

bool operator>(CInt c1, int c2) {
    return c1.value > c2;
}

bool operator<(CInt c1, int c2) {
    return c1.value < c2;
}
