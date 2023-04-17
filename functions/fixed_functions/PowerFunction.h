//
// Created by artem on 17.04.2023.
//

#ifndef VM1_POWERFUNCTION_H
#define VM1_POWERFUNCTION_H

#include "FixedFunction.h"

class PowerFunction : public FixedFunction {

public:

    PowerFunction(const CVector<CDouble> &_coefficients);

    double f(double x) override;

};


#endif //VM1_POWERFUNCTION_H
