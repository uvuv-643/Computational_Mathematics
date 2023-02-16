//
// Created by artem on 10.02.2023.
//
#pragma once
#ifndef VM1_CINT_H
#define VM1_CINT_H

#include <iostream>
#include <cstdint>

using namespace std;

class CInt {
protected:
    int32_t value;
public:
    CInt();

    CInt(int32_t _value);

    operator int32_t() const { return value; }

    operator size_t() const { return value; }

    friend ostream &operator<<(ostream &os, const CInt &validated);

    friend istream &operator>>(istream &is, CInt &data);

    friend CInt operator+(CInt lhs, const CInt &rhs);

    friend CInt operator+(CInt lhs, const int &rhs);

    CInt &operator+=(const CInt &rhs);

    CInt &operator+=(const int &rhs);

    friend const CInt operator++(CInt &i, int);

    friend bool operator==(CInt c1, CInt c2);

    friend bool operator!=(CInt c1, CInt c2);

    friend bool operator>(CInt c1, CInt c2);

    friend bool operator<(CInt c1, CInt c2);

    friend bool operator==(CInt c1, int c2);

    friend bool operator!=(CInt c1, int c2);

    friend bool operator>(CInt c1, int c2);

    friend bool operator<(CInt c1, int c2);

};

#endif //VM1_CINT_H
