//
// Created by artem on 17.04.2023.
//

#ifndef VM1_FIXEDFUNCTION_H
#define VM1_FIXEDFUNCTION_H

#include "../../data_structures/CVector.h"

class FixedFunction {

protected:
    CVector<CDouble> coefficients;
public:

    virtual double f(double x) = 0;

    CVector<CDouble> apply(CVector<CDouble> x);
};


#endif //VM1_FIXEDFUNCTION_H
