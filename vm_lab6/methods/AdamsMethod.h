//
// Created by K49-R355-M11 on 20.05.2023.
//

#ifndef COMPUTATIONAL_MATHEMATICS_ADAMSMETHOD_H
#define COMPUTATIONAL_MATHEMATICS_ADAMSMETHOD_H

#define INF 1e9 + 7
#define LIMIT_OF_ITERATIONS 10
#ifndef METHOD_K
#define METHOD_K 15
#endif

#include <vector>
#include <utility>
#include <iostream>
#include "../functions/CDifferentialFunctionManager.h"
#include "EulerModified.h"

class AdamsMethod {

    double x_0;
    double x_n;
    double y_0;
    double h;
    double eps;

    vector<double> y_initial;

    vector<double> simple_iteration(CDifferentialFunction* function, double h);

public:

    AdamsMethod(double x_0, double x_n, double y_0, double h, double eps);
    pair<double, vector<double>> perform_method(CDifferentialFunction* function);

};


#endif //COMPUTATIONAL_MATHEMATICS_ADAMSMETHOD_H
