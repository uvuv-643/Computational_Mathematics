//
// Created by artem on 26.02.2023.
//

#include "CNewtonMethod.h"

CNewtonResult CNewtonMethod::performMethod(CFunctionMV* f, CFunctionMV* g, double initial_x, double initial_y, double eps) {
    CDouble x = initial_x;
    CDouble y = initial_y;
    MultipleFunctionMethodData initial_data(f, g, x, y, eps);
    CNewtonResult result = *new CNewtonResult(METHOD_CAN_BE_APPLIED, initial_data);
    for (size_t current_iteration = 0; current_iteration < LIMIT_OF_ITERATIONS; current_iteration++) {
        double a = f->f_derivative_x(x, y);
        double b = f->f_derivative_y(x, y);
        double c = g->f_derivative_x(x, y);
        double d = g->f_derivative_y(x, y);
        double f_value = f->f(x, y);
        double g_value = g->f(x, y);
        CDouble dx = 0, dy = 0;
        if (a != 0 && (d - (b * c / a) != 0)) {
            dy = (-g_value + c * f_value / a) / (d - (b * c / a));
            dx = (-f_value - b * dy) / a;
        }
        x += dx;
        y += dy;
        result.append(x, y, dx, dy);
        if (abs(f->f(x, y)) <= eps && abs(g->f(x, y)) <= eps) break;
    }
    result.setMethodResult(METHOD_WAS_SUCCESSFULLY_FINISHED);
    return result;
}