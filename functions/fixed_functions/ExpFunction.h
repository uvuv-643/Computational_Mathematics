//
// Created by artem on 17.04.2023.
//

#ifndef VM1_EXPFUNCTION_H
#define VM1_EXPFUNCTION_H

#include "FixedFunction.h"

class ExpFunction : public FixedFunction {

    CVector<CDouble> coefficients;

public:

    explicit ExpFunction(const CVector<CDouble>& _coefficients);
    double f(double x) override;

};


#endif //VM1_EXPFUNCTION_H
