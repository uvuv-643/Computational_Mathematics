//
// Created by artem on 10.02.2023.
//

#include "CSize.h"

istream &operator>>(istream &is, CSize &data) {
    int32_t inputted;
    while (!(is >> inputted) || inputted <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cerr << "Wrong input" << endl;
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
