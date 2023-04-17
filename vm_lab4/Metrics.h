//
// Created by artem on 16.04.2023.
//

#ifndef VM1_METRICS_H
#define VM1_METRICS_H

#include "../data_structures/CVector.h"

class Metrics {

public:

    static double corr(CVector<CDouble> &x, CVector<CDouble> &y);

    static double mse(CVector<CDouble> &y_true, CVector<CDouble> &y_pred);

    static double sd(CVector<CDouble> &y_true, CVector<CDouble> &y_pred);

    static double r2_score(CVector<CDouble> &y_true, CVector<CDouble> &y_pred);

};


#endif //VM1_METRICS_H
