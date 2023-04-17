//
// Created by artem on 17.04.2023.
//

#ifndef VM1_LOGREGRESSION_H
#define VM1_LOGREGRESSION_H

#include "PolynomialRegression.h"

class LogRegression : public PolynomialRegression {
public:

    LogRegression();

    CVector<CDouble> performMethod(size_t number_of_points, CVector<CDouble>& x, CVector<CDouble>& y);

    static string createDefinition(CVector<CDouble> answer);

};


#endif //VM1_LOGREGRESSION_H
