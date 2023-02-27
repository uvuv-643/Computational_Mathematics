//
// Created by artem on 24.02.2023.
//

#include "CIterationsMethod.h"

enum MethodResult CIterationsMethod::validateBorder(CFunctionSV* function_data, float border_left, float border_right) {
    if (function_data->f(border_left) * function_data->f(border_right) > 0) {
        return WRONG_NUMBER_OF_SOLUTIONS;
    }
    float dx = (border_right - border_left) / DELTA;
    for (float current_point = border_left; current_point <= border_right; current_point += dx) {
        if (abs(function_data->phi_derivative(current_point)) >= 1) {
            return LIPSCHITZ_CONSTANT_GREATER_THAN_ONE;
        }
    }
    return METHOD_CAN_BE_APPLIED;
}

CIterationsResult CIterationsMethod::performMethod(CFunctionSV* function_data, float initial_border_left, float initial_border_right, float eps) {
    CFloat border_left = initial_border_left;
    CFloat border_right = initial_border_right;
    CIterationsResult result = *new CIterationsResult(validateBorder(function_data, border_left, border_right));
    if (result.getMethodResult() == METHOD_CAN_BE_APPLIED) {
        vector<CFloat> xs;
        xs.push_back(border_left);
        for (size_t current_iteration = 0; current_iteration < LIMIT_OF_ITERATIONS; current_iteration++) {
            CFloat x_prev = xs[current_iteration];
            CFloat x_current = function_data->phi(x_prev);
            xs.push_back(x_current);
            if (abs(function_data->f(x_current)) < eps) break;
        }
        for (size_t i = 0; i < xs.size() - 1; i++) {
            result.append(xs[i], xs[i + 1]);
        }
        result.setMethodResult(METHOD_WAS_SUCCESSFULLY_FINISHED);
    }
    return result;
}
