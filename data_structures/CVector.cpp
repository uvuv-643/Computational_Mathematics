//
// Created by artem on 11.02.2023.
//

#include "CVector.h"

template<typename T>
CVector<T>::CVector() {
    this->n = 0;
    vector<T> v(n);
    this->data = v;
}

template<typename T>
CVector<T>::CVector(size_t _n) {
    this->n = _n;
    vector<T> v(this->n);
    this->data = v;
}

template<typename T>
ostream& operator<<(ostream& os,  CVector<T>& vector) {
    size_t n = vector.n;
    os << n << endl;
    for (size_t row = 0; row < n; row++) {
        os << vector[row] << " ";
    }
    os << endl;
    return os;
}

template<typename T>
istream& operator>>(istream& is, CVector<T>& vector) {
    if (vector.data.size() == 0) {
        is >> vector.n;
    }
    size_t n = vector.n;
    vector.data.resize(n);
    for (size_t row = 0; row < n; row++) {
        if (std::getenv("DEBUG_MODE")) {
            cerr << "Input a[" << row << "]" << endl;
        }
        is >> vector[row];
    }
    return is;
}

template<typename T>
T& CVector<T>::operator [] (size_t i) {
    return this->data[i];
}