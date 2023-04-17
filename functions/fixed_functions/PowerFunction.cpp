//
// Created by artem on 17.04.2023.
//

#include "PowerFunction.h"

PowerFunction::PowerFunction(const CVector<CDouble> &_coefficients) {
    this->coefficients = _coefficients;
}

double PowerFunction::f(double x) {
    return exp(coefficients[0]) * pow(x, coefficients[1]);
}
