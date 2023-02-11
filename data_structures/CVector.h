//
// Created by artem on 11.02.2023.
//
#pragma once
#ifndef VM1_CVECTOR_H
#define VM1_CVECTOR_H


#include <vector>
#include <stdint.h>
#include <iomanip>
#include "../io/CSize.h"

#define MAXIMUM_DISPLAYED_SYMBOLS_IN_MATRIX 14

using namespace std;

template<typename T>
class CVector {
protected:
    vector<T> data;
public:
    CSize n;

    CVector();

    CVector(size_t n);

    template<typename U>
    friend ostream &operator<<(ostream &os, CVector<U> &vector);

    template<typename U>
    friend istream &operator>>(istream &os, CVector<U> &vector);

    T &operator[](size_t i);

};


#endif //VM1_CVECTOR_H
