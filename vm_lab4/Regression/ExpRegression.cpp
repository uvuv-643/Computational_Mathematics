//
// Created by artem on 17.04.2023.
//

#include "ExpRegression.h"

CVector<CDouble> ExpRegression::performMethod(size_t number_of_points, CVector<CDouble>& x, CVector<CDouble>& y) {
    return PolynomialRegression::performMethod(number_of_points, x, y.apply(log));
}

ExpRegression::ExpRegression() : PolynomialRegression(1) {

}

string ExpRegression::createDefinition(CVector<CDouble> answer) {
    string definition = "exp(";
    definition += to_string(answer[0]) + " + " + to_string(answer[1]) + " * x";
    return definition + ")";
}