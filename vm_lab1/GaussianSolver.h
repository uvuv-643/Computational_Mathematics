//
// Created by artem on 16.04.2023.
//

#ifndef VM1_GAUSSIANSOLVER_H
#define VM1_GAUSSIANSOLVER_H

#include <utility>
#include <vector>
#include <cmath>
#include "../data_structures/CVector.h"
#include "../data_structures/Matrix.h"

using namespace std;

class GaussianSolver {
private:
    Matrix<CDouble> A;
    CVector<CDouble> b;
    int n;

public:

    GaussianSolver(const Matrix<CDouble> &_a, const CVector<CDouble> &_b);

    CVector<CDouble> solve();

};


#endif //VM1_GAUSSIANSOLVER_H
