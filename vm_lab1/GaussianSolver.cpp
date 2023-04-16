//
// Created by artem on 16.04.2023.
//

#include "GaussianSolver.h"

GaussianSolver::GaussianSolver(const Matrix<CFloat> &_a, const CVector<CFloat> &_b)  {
    A = _a;
    b = _b;
    n = b.n;
}

CVector<CFloat> GaussianSolver::solve() {
    for (int i = 0; i < n; i++) {
        int max_index = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(A[j][i]) > abs(A[max_index][i]))
                max_index = j;
        }
        swap(A[i], A[max_index]);
        swap(b[i], b[max_index]);
        for (int j = i + 1; j < n; j++) {
            float factor = A[j][i] / A[i][i];
            for (int k = i; k < n; k++) {
                A[j][k] = A[j][k] - factor * A[i][k];
            }
            b[j] = b[j] - factor * b[i];
        }
    }

    CVector<CFloat> x(n);
    for (int i = n - 1; i >= 0; i--) {
        float sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }
    return x;
}
