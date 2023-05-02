//
// Created by artem on 01.05.2023.
//

#include "Lg.h"

CDouble Lg::performMethod(DiscreteFunction &df, CDouble target_x) {
    vector<CDouble> x = df.getX().data;
    vector<CDouble> y = df.getY().data;
    double y_val = 0;
    for (int i = 0; i < x.size(); i++) {
        double L_i = 1;
        for (int j = 0; j < x.size(); j++) {
            if (j != i) {
                L_i *= (target_x - x[j]) / (x[i] - x[j]);
            }
        }
        y_val += L_i * y[i];
    }
    return y_val;
}
