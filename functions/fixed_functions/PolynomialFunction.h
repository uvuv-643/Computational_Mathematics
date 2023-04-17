//
// Created by artem on 17.04.2023.
//

#ifndef VM1_POLYNOMIALFUNCTION_H
#define VM1_POLYNOMIALFUNCTION_H

#include "FixedFunction.h"

class PolynomialFunction : public FixedFunction {

    size_t p;

public:

    PolynomialFunction(size_t _p, const CVector<CDouble> &_coefficients);

    double f(double x) override;

};


#endif //VM1_POLYNOMIALFUNCTION_H
