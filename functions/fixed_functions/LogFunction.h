//
// Created by artem on 17.04.2023.
//

#ifndef VM1_LOGFUNCTION_H
#define VM1_LOGFUNCTION_H

#include "FixedFunction.h"

class LogFunction : public FixedFunction {

public:

    LogFunction(const CVector<CDouble> &_coefficients);

    double f(double x) override;

};


#endif //VM1_LOGFUNCTION_H
