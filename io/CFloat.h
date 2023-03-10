//
// Created by artem on 10.02.2023.
//
#pragma once
#ifndef VM1_CFLOAT_H
#define VM1_CFLOAT_H

#include <iostream>

using namespace std;

class CFloat {
protected:
    float value;
public:
    CFloat();

    CFloat(float _value);

    operator float() const { return value; }

    friend ostream &operator<<(ostream &os, const CFloat &validated);

    friend istream &operator>>(istream &is, CFloat &data);

    friend CFloat operator+(CFloat lhs, const CFloat &rhs);

    CFloat &operator+=(const CFloat &rhs);
};


#endif //VM1_CFLOAT_H
