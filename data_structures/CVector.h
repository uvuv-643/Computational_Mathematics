//
// Created by artem on 11.02.2023.
//
#pragma once
#ifndef VM1_CVECTOR_H
#define VM1_CVECTOR_H


#include <vector>
#include <cstdint>
#include <iomanip>
#include <random>
#include <functional>
#include <algorithm>
#include "../io/CFloat.h"
#include "../io/CSize.h"

#define MAXIMUM_DISPLAYED_SYMBOLS_IN_VECTOR 15
#define VECTOR_GENERATION_MAXIMUM_VALUE_BY_MODULO 100

using namespace std;

template<typename T>
class CVector {
protected:
    vector<T> data;
public:
    CSize n;

    CVector();

    CVector(size_t n);

    CVector(const CVector<T> & vector);

    void setRandom();

    template<typename U>
    friend ostream &operator<<(ostream &os, CVector<U> &vector);

    template<typename U>
    friend istream &operator>>(istream &os, CVector<U> &vector);

    template<typename U>
    friend CVector<U> &operator -(CVector<U> &l, CVector<U> &r);

    T &operator[](size_t i);

    void push_back(T element);
    void push_front(T element);

    CVector<T> &operator=(const CVector<T> &other);

    CVector<CFloat> apply(float (*pFunction)(float));

    static CVector<CFloat> apply(CVector<CFloat>* x, CVector<CFloat>* y, float (*pFunction)(float, float));

};

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
void CVector<T>::push_front(T element) {
    this->data.push_back(element);
    std::rotate(this->data.rbegin(), this->data.rbegin() + 1, this->data.rend());
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
    size_t vector_size = min(l.n, r.n);
    for (size_t i = 0; i < vector_size; i++) {
        l[i] = r[i] - l[i];
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

template<typename T>
CVector<CFloat> CVector<T>::apply(CVector<CFloat>* x, CVector<CFloat>* y, float (*pFunction)(float, float)) {
    CVector<CFloat> new_vector = *new CVector<CFloat>(x->n);
    if (x->n == y->n) {
        for (size_t i = 0; i < x->data.size(); i++) {
            new_vector[i] = pFunction(x->data[i], y->data[i]);
        }
    }
    return new_vector;
}

template<typename T>
CVector<T>::CVector(const CVector<T> &vector) {
    this->data = vector.data;
    this->n = vector.n;
}

#endif //VM1_CVECTOR_H
