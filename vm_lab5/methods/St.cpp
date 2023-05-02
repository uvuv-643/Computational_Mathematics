//
// Created by artem on 02.05.2023.
//

#include "St.h"

static double factorial(size_t n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

CDouble St::performMethod(DiscreteFunction &df, CDouble target_x) {
    CVector<CDouble> x = df.getX();
    CVector<CDouble> y = df.getY();
    size_t number_of_points = x.n;
    if (number_of_points % 2 == 1) {
        CTable finiteDifferences = Gs::getTableOfFiniteDifferences(df);
        vector<vector<double>> fd = finiteDifferences.getData();
        size_t n = number_of_points / 2;
        double h = x[1] - x[0];
        double answer = y[n];
        for (size_t i = 1; i <= n; i++) {
            double current_product = 1;
            double t = (target_x - x[n]) / h;
            for (size_t j = 0; j < i; j++) {
                current_product *= (t * t - j * j);
            }
            current_product /= factorial(2 * i);
            current_product *= fd[n - i][2 * i + 1];
            answer += current_product;
        }
        for (size_t i = 1; i < n; i++) {
            double current_product = 1;
            double t = (target_x - x[n]) / h;
            for (size_t j = 0; j < i; j++) {
                current_product *= (t * t - j * j);
            }
            current_product /= t;
            current_product /= 2 * factorial(2 * i - 1);
            current_product *= (fd[n - i][2 * i] + fd[n - i + 1][2 * i]);
            answer += current_product;
        }
        return answer;
    }

    return 0;

}
