//
// Created by artem on 17.04.2023.
//

#include "FixedFunction.h"

CVector<CDouble> FixedFunction::apply(CVector<CDouble> x) {
    CVector<CDouble> y_pred = x;
    for (size_t i = 0; i < (size_t) x.n; i++) {
        y_pred[i] = this->f(x[i]);
    }
    return y_pred;
}
