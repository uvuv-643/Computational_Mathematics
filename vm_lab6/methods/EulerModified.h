//
// Created by K49-R355-M11 on 20.05.2023.
//

#ifndef COMPUTATIONAL_MATHEMATICS_EULERMODIFIED_H
#define COMPUTATIONAL_MATHEMATICS_EULERMODIFIED_H

#define INF 1e9 + 7
#define LIMIT_OF_ITERATIONS 10
#ifndef METHOD_K
#define METHOD_K 3
#endif

#include <vector>
#include <utility>
#include <iostream>
#include "../functions/CDifferentialFunctionManager.h"

class EulerModified {

    double x_0;
    double x_n;
    double y_0;
    double h;
    double eps;
    size_t limit;

    vector<double> simple_iteration(CDifferentialFunction* function, double h, size_t number_of_iteration);

public:

    EulerModified(double x_0, double x_n, double y_0, double h, double eps, size_t limit = INF);
    pair<double, vector<double>> perform_method(CDifferentialFunction* function);

};


#endif //COMPUTATIONAL_MATHEMATICS_EULERMODIFIED_H
