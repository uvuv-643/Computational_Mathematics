//
// Created by artem on 17.04.2023.
//

#include "ExpFunction.h"

ExpFunction::ExpFunction(const CVector<CDouble> &_coefficients) {
    this->coefficients = _coefficients;
}

double ExpFunction::f(double x) {
    return exp((double) coefficients[0] + coefficients[1] * x);
}


