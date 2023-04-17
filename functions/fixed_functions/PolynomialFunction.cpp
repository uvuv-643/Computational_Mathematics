//
// Created by artem on 17.04.2023.
//

#include "PolynomialFunction.h"

double PolynomialFunction::f(double x) {
    double answer = 0;
    for (size_t i = 0; i < p + 1; i++) {
        answer += this->coefficients[i] * pow(x, i);
    }
    return answer;
}

PolynomialFunction::PolynomialFunction(size_t _p, const CVector<CDouble>& _coefficients) {
    this->p = _p;
    this->coefficients = _coefficients;
}
