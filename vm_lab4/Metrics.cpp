//
// Created by artem on 16.04.2023.
//

#include "Metrics.h"

double Metrics::corr(CVector<CDouble>& x, CVector<CDouble>& y) {
    CDouble x_mean = x.mean();
    CDouble y_mean = y.mean();
    CVector<CDouble> tx = (x - x_mean);
    CVector<CDouble> ty = (y - y_mean);
    double s1 = CVector<CDouble>::apply(&tx, &ty, [] (double x, double y) { return x * y; }).sum();
    double s2 = (x - x_mean).apply([](double t) { return pow(t, 2); }).sum();
    double s3 = (y - y_mean).apply([](double t) { return pow(t, 2); }).sum();
    return s1 / sqrt(s2 * s3);
}

double Metrics::mse(CVector<CDouble> &y_true, CVector<CDouble> &y_pred) {
    return (y_true - y_pred).apply([](double t) { return pow(t, 2); }).sum();
}

double Metrics::sd(CVector<CDouble> &y_true, CVector<CDouble> &y_pred) {
    size_t n = y_true.n;
    return sqrt(Metrics::mse(y_true, y_pred) / (double) n);
}

double Metrics::r2_score(CVector<CDouble> &y_true, CVector<CDouble> &y_pred) {
    CDouble y_pred_mean = y_pred.mean();
    double mse = Metrics::mse(y_true, y_pred);
    double variance = (y_true - y_pred_mean).apply([](double t) { return pow(t, 2); }).sum();
    return 1 - mse / variance;
}

