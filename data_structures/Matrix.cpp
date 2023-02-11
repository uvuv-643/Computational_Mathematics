//
// Created by artem on 10.02.2023.
//

#include "Matrix.h"
#include <typeinfo>

template<typename T>
Matrix<T>::Matrix() {
    this->n = 1;
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
    for (size_t row = 0; row < n; row++) {
        for (size_t col = 0; col < n; col++) {
            os << setw(MAXIMUM_DISPLAYED_SYMBOLS_IN_MATRIX) << left << matrix[row][col] << " ";
        }
        cout << endl;
    }
    return os;
}

template<typename T>
istream& operator>>(istream& is, Matrix<T>& matrix) {
    is >> matrix.n;
    size_t n = matrix.n;
    matrix.matrix.resize(n, vector<T>(n));
    for (size_t row = 0; row < n; row++) {
        for (size_t col = 0; col < n; col++) {
            if (std::getenv("DEBUG_MODE")) {
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