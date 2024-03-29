//
// Created by artem on 10.02.2023.
//

#pragma once
#include "CSize.h"

istream &operator>>(istream &is, CSize &data) {
    int32_t inputted;
    while ((!(is >> inputted) || inputted <= 0 || abs((int)inputted - inputted) > 0.0001) && !is.eof()) {
        is.clear();
        is.ignore(1000, '\n');
        if (&is == &cin) {
            cerr << "Wrong input" << endl;
        }
    }
    data.value = inputted;
    return is;
}

CSize::CSize() {
    this->value = 0;
}

CSize::CSize(int _value) {
    this->value = _value;
}
