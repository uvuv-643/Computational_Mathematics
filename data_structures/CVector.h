//
// Created by artem on 11.02.2023.
//
#pragma once
#ifndef VM1_CVECTOR_H
#define VM1_CVECTOR_H


#include <vector>
#include <cstdint>
#include <iomanip>
#include "../io/CSize.cpp"

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

#endif //VM1_CVECTOR_H
