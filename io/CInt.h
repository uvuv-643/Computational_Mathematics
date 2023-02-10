//
// Created by artem on 10.02.2023.
//

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
    friend ostream &operator<<(ostream &os, const CInt &validated);
    friend istream &operator>>(istream &is, CInt &data);
};

#endif //VM1_CINT_H
