//
// Created by artem on 17.04.2023.
//

#include "LogRegression.h"

CVector<CDouble> LogRegression::performMethod(size_t number_of_points, CVector<CDouble>& x, CVector<CDouble>& y) {
    return PolynomialRegression::performMethod(number_of_points, x.apply(log), y);
}

LogRegression::LogRegression() : PolynomialRegression(1) {

}

string LogRegression::createDefinition(CVector<CDouble> answer) {
    return to_string(answer[0]) + " + " + to_string(answer[1]) + "* log(x)";
}
