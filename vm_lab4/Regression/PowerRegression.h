//
// Created by artem on 17.04.2023.
//

#ifndef VM1_POWERREGRESSION_H
#define VM1_POWERREGRESSION_H

#include "PolynomialRegression.h"

class PowerRegression : public PolynomialRegression {

public:

    PowerRegression();

    CVector<CDouble> performMethod(size_t number_of_points, CVector<CDouble>& x, CVector<CDouble>& y);

    static string createDefinition(CVector<CDouble> answer);

};


#endif //VM1_POWERREGRESSION_H
