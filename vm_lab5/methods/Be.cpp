//
// Created by artem on 02.05.2023.
//

#include "Be.h"

static double factorial(size_t n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

CDouble Be::performMethod(DiscreteFunction &df, CDouble target_x) {
    CVector<CDouble> x = df.getX();
    CVector<CDouble> y = df.getY();
    size_t number_of_points = x.n;
//    if (number_of_points % 2 == 1) {
//        CTable finiteDifferences = Gs::getTableOfFiniteDifferences(df);
//        vector<vector<double>> fd = finiteDifferences.getData();
//        size_t n = number_of_points / 2;
//        double h = x[1] - x[0];
//        double answer = (y[n] + y[n - 1]) / 2;
//        for (size_t i = 1; i <= n; i++) {
//            double current_product = 1;
//            for (size_t j = 1; j <= 2 * i + 2; j++) {
//                current_product *= ((target_x - x[n]) / h) + ((int32_t)(j / 2) * pow(-1, j + 1));
//            }
//            current_product /= factorial(2 * i + 1);
//            current_product *= fd[n - i][2 * i + 2];
//            answer += current_product;
//        }
//        for (size_t i = 0; i < n; i++) {
//            double current_product = 1;
//            for (size_t j = 1; j < 2 * i + 3; j++) {
//                current_product *= ((target_x - x[n]) / h) + ((int32_t)(j / 2) * pow(-1, j + 1));
//            }
//            current_product /= factorial(2 * i + 2);
//            current_product *= fd[n - i - 1][2 * i + 3];
//            answer += current_product;
//        }
//        return answer;
//    }

    return 0;

}