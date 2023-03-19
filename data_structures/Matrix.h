//
// Created by artem on 10.02.2023.
//
#pragma once
#ifndef VM1_MATRIX_H
#define VM1_MATRIX_H

#include <vector>
#include <cstdint>
#include <random>
#include <set>
#include <iomanip>
#include <functional>
#include "../io/CSize.h"

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

template<typename T>
void Matrix<T>::setRandom() {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-MATRIX_GENERATION_MAXIMUM_VALUE_BY_MODULO, MATRIX_GENERATION_MAXIMUM_VALUE_BY_MODULO);
    std::uniform_int_distribution<int> index_distribution(0, (size_t) n - 1);
    auto random_number = std::bind(distribution, generator);
    auto random_index = std::bind(index_distribution, generator);
    set<size_t> used_rows;
    for (size_t i = 0; i < (size_t) n; i++) {
        size_t target_col = 0;
        do {
            target_col = random_index() % (size_t) n;
        } while (used_rows.count(target_col) != 0);
        used_rows.insert(target_col);
        for (size_t j = 0; j < (size_t) n; j++) {
            this->matrix[i][j] = random_number();
            if (j == target_col) {
                this->matrix[i][j] = this->matrix[i][j] * MATRIX_DIAGONAL_DOMINANCE_COEFFICIENT;
            }
        }
    }
}


#endif //VM1_MATRIX_H
