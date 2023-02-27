//
// Created by artem on 26.02.2023.
//

#include "CNewtonMethod.h"

CNewtonResult CNewtonMethod::performMethod(CFunctionMV* f, CFunctionMV* g, float initial_x, float initial_y, float eps) {
    CFloat x = initial_x;
    CFloat y = initial_y;
    CNewtonResult result = *new CNewtonResult(METHOD_CAN_BE_APPLIED);
    for (size_t current_iteration = 0; current_iteration < LIMIT_OF_ITERATIONS; current_iteration++) {
        float a = f->f_derivative_x(x, y);
        float b = f->f_derivative_y(x, y);
        float c = g->f_derivative_x(x, y);
        float d = g->f_derivative_y(x, y);
        float f_value = f->f(x, y);
        float g_value = g->f(x, y);
        CFloat dx = 0, dy = 0;
        if (a != 0 && (d - (b * c / a) != 0)) {
            dy = (-g_value + c * f_value / a) / (d - (b * c / a));
            dx = (-f_value - b * dy) / a;
        }
        x += dx;
        y += dy;
        result.append(x, y, dx, dy);
        if (f->f(x, y) <= eps && g->f(x, y) <= eps) break;
    }
    result.setMethodResult(METHOD_WAS_SUCCESSFULLY_FINISHED);
    return result;
}