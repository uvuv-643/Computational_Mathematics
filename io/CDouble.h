//
// Created by artem on 10.02.2023.
//
#pragma once
#ifndef VM1_CDOUBLE_H
#define VM1_CDOUBLE_H

#include <iomanip>
#include <algorithm>
#include <iostream>

using namespace std;

class CDouble {
protected:
    double value;
public:
    CDouble();

    CDouble(double _value);

    operator double() const { return value; }

    friend ostream &operator<<(ostream &os, const CDouble &validated);

    friend istream &operator>>(istream &is, CDouble &data);

    friend CDouble operator+(CDouble lhs, const CDouble &rhs);

    CDouble &operator+=(const CDouble &rhs);
};


#endif //VM1_CDOUBLE_H
