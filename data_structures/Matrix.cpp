//
// Created by artem on 10.02.2023.
//
#pragma once
#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix() {
    this->n = 0;
    vector<vector<T>> v(this->n, vector<T>(this->n));
    this->matrix = v;
}

template<typename T>
Matrix<T>::Matrix(size_t _n) {
    this->n = _n;
    vector<vector<T>> v(this->n, vector<T>(this->n));
    this->matrix = v;
}

template<typename T>
ostream& operator<<(ostream& os,  Matrix<T>& matrix) {
    size_t n = matrix.n;
    os << n << endl;
    for (size_t row = 0; row < n; row++) {
        for (size_t col = 0; col < n; col++) {
            os << setw(MAXIMUM_DISPLAYED_SYMBOLS_IN_MATRIX) << left << matrix[row][col] << " ";
        }
        os << endl;
    }
    return os;
}

template<typename T>
istream& operator>>(istream& is, Matrix<T>& matrix) {
    if (matrix.matrix.size() == 0) {
        is >> matrix.n;
    }
    size_t n = matrix.n;
    matrix.matrix.resize(n, vector<T>(n));
    for (size_t row = 0; row < n; row++) {
        for (size_t col = 0; col < n; col++) {
            if (&is == &cin) {
                cerr << "Input a[" << row << "][" << col << "]" << endl;
            }
            is >> matrix[row][col];
        }
    }
    return is;
}

template<typename T>
vector<T>& Matrix<T>::operator [] (size_t i) {
    return this->matrix[i];
}