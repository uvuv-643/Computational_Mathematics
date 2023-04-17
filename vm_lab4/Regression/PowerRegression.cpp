//
// Created by artem on 17.04.2023.
//

#include "PowerRegression.h"

CVector<CDouble> PowerRegression::performMethod(size_t number_of_points, CVector<CDouble>& x, CVector<CDouble>& y) {
    return PolynomialRegression::performMethod(number_of_points, x.apply(log), y.apply(log));
}

PowerRegression::PowerRegression() : PolynomialRegression(1) {

}

string PowerRegression::createDefinition(CVector<CDouble> answer) {
    return "exp(" + to_string(answer[0]) + ") * x^" + to_string(answer[1]);
}


