//
// Created by artem on 16.04.2023.
//

#ifndef VM1_POLYNOMIALREGRESSION_H
#define VM1_POLYNOMIALREGRESSION_H

#include "../data_structures/CVector.h"
#include "../data_structures/Matrix.h"
#include "../vm_lab1/GaussianSolver.h"

class PolynomialRegression {

    size_t p;

public:

    PolynomialRegression(size_t p);

    CVector<CDouble> performMethod(size_t number_of_points, CVector<CDouble> x, CVector<CDouble> y) const;

};


#endif //VM1_POLYNOMIALREGRESSION_H
