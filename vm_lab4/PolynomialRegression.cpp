//
// Created by artem on 16.04.2023.
//

#include "PolynomialRegression.h"

CVector<CDouble> PolynomialRegression::performMethod(size_t number_of_points, CVector<CDouble> x, CVector<CDouble> y) const {

    size_t n = this->p + 1;
    Matrix<CDouble> a(n);
    CVector<CDouble> b(n);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            double t = 0;
            for (size_t k = 0; k < number_of_points; k++) {
                t += pow(x[k], (double)(i + j));
            }
            a[i][j] = t;
        }
    }
    for (size_t i = 0; i < n; i++) {
        double t = 0;
        for (size_t k = 0; k < number_of_points; k++) {
            t += y[k] * pow(x[k], (double) i);
        }
        b[i] = t;
    }

    CVector<CDouble> answer = GaussianSolver(a, b).solve();
    return answer;

}

PolynomialRegression::PolynomialRegression(size_t p) {
    this->p = p;
}
