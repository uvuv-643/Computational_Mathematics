//
// Created by artem on 10.02.2023.
//

#pragma once
#include "CSize.h"

istream &operator>>(istream &is, CSize &data) {
    int32_t inputted;
    if (&is == &cin) {
        cerr << "Input size:" << endl;
    }
    while ((!(is >> inputted) || inputted <= 0) && !is.eof()) {
        is.clear();
        is.ignore(1000, '\n');
        if (std::getenv("DEBUG_MODE")) {
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
