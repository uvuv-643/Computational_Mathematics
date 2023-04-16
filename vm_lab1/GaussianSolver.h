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
    Matrix<CFloat> A;
    CVector<CFloat> b;
    int n;

public:

    GaussianSolver(const Matrix<CFloat> &_a, const CVector<CFloat> &_b);

    CVector<CFloat> solve();

};


#endif //VM1_GAUSSIANSOLVER_H
