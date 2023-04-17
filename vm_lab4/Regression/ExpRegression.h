//
// Created by artem on 17.04.2023.
//

#ifndef VM1_EXPREGRESSION_H
#define VM1_EXPREGRESSION_H


#include "PolynomialRegression.h"

class ExpRegression : public PolynomialRegression {

public:

    ExpRegression();

    CVector<CDouble> performMethod(size_t number_of_points, CVector<CDouble>& x, CVector<CDouble>& y);

    static string createDefinition(CVector<CDouble> answer);

};

#endif //VM1_EXPREGRESSION_H
