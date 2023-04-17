//
// Created by artem on 17.04.2023.
//

#include "LogFunction.h"

LogFunction::LogFunction(const CVector<CDouble> &_coefficients) {
    this->coefficients = _coefficients;
}

double LogFunction::f(double x) {
    return (double) coefficients[0] + coefficients[1] * log(x);
}
