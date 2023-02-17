//
// Created by artem on 10.02.2023.
//
#pragma once
#ifndef VM1_MATRIX_H
#define VM1_MATRIX_H

#include <vector>
#include <cstdint>
#include <random>
#include <iomanip>
#include "../io/CSize.cpp"

#define MAXIMUM_DISPLAYED_SYMBOLS_IN_MATRIX 14
#define MATRIX_GENERATION_MAXIMUM_VALUE_BY_MODULO 100
#define MATRIX_DIAGONAL_DOMINANCE_COEFFICIENT 500

using namespace std;

template<typename T>
class Matrix {
protected:
    vector<vector<T>> matrix;
public:
    CSize n;

    Matrix();

    Matrix(size_t n);

    void setRandom();

    template<typename U>
    friend ostream &operator<<(ostream &os, Matrix<U> &matrix);

    template<typename U>
    friend istream &operator>>(istream &os, Matrix<U> &matrix);

    vector<T>& operator[](size_t i);

};


#endif //VM1_MATRIX_H
