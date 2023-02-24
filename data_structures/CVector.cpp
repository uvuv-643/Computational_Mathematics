//
// Created by artem on 11.02.2023.
//
#pragma once

#include <random>
#include <functional>
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
    for (size_t row = 0; row < n; row++) {
        os << setw(MAXIMUM_DISPLAYED_SYMBOLS_IN_VECTOR) << right << vector[row] << " ";
    }
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
        if (&is == &cin) {
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

template<typename T>
void CVector<T>::push_back(T element) {
    this->data.push_back(element);
    this->n++;
}

template<typename T>
CVector<T> &CVector<T>::operator=(const CVector<T> &other) {
    if (this == &other) {
        return *this;
    }
    this->n = other.n;
    this->data = other.data;
    return *this;
}

template<typename T>
void CVector<T>::setRandom() {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-VECTOR_GENERATION_MAXIMUM_VALUE_BY_MODULO, VECTOR_GENERATION_MAXIMUM_VALUE_BY_MODULO);
    auto random_number = std::bind(distribution, generator);
    for (size_t i = 0; i < (size_t) n; i++) {
        this->data[i] = random_number();
    }
}

template<typename U>
CVector<U> &operator-(CVector<U> &l, CVector<U> &r) {
    if (l.n == r.n) {
        size_t vector_size = l.n;
        for (size_t i = 0; i < vector_size; i++) {
            l[i] = r[i] - l[i];
        }
    }
    return l;
}

template<typename T>
CVector<CFloat> CVector<T>::apply(float (*pFunction)(float)) {
    CVector<CFloat> new_vector = *new CVector<CFloat>(this->n);
    for (size_t i = 0; i < this->data.size(); i++) {
        new_vector[i] = pFunction(this->data[i]);
    }
    return new_vector;
}
