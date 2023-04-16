//
// Created by artem on 16.04.2023.
//

#include "PolynomialRegression.h"

CVector<CFloat> PolynomialRegression::performMethod(size_t number_of_points, CVector<CFloat> x, CVector<CFloat> y) const {

    size_t n = this->p + 1;
    Matrix<CFloat> a(n);
    CVector<CFloat> b(n);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            float t = 0;
            for (size_t k = 0; k < number_of_points; k++) {
                t += pow(x[k], (float)(i + j));
            }
            a[i][j] = t;
        }
    }
    for (size_t i = 0; i < n; i++) {
        float t = 0;
        for (size_t k = 0; k < number_of_points; k++) {
            t += y[k] * pow(x[k], (float) i);
        }
        b[i] = t;
    }

    CVector<CFloat> answer = GaussianSolver(a, b).solve();
    return answer;

}

PolynomialRegression::PolynomialRegression(size_t p) {
    this->p = p;
}
