//
// Created by artem on 10.02.2023.
//

#include "CInt.h"

ostream &operator<<(ostream &os, const CInt &validated) {
    os << validated.value;
    return os;
}

istream &operator>>(istream &is, CInt &data) {
    int32_t inputted;
    if (std::getenv("DEBUG_MODE")) {
        cerr << "Input int:" << endl;
    }
    while (!(is >> inputted)) {
        cin.clear();
        cin.ignore(1000, '\n');
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
