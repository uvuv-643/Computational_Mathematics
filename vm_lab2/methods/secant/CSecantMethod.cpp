//
// Created by artem on 24.02.2023.
//

#include "CSecantMethod.h"

enum MethodResult CSecantMethod::validateBorder(CFunctionSV* function_data, double border_left, double border_right) {
    if (function_data->f(border_left) * function_data->f(border_right) > 0) {
        return WRONG_NUMBER_OF_SOLUTIONS;
    }
    double dx = (border_right - border_left) / DELTA;
    bool derivative_sign = function_data->f_derivative(border_left) > 0;
    bool second_derivative_sign = function_data->f_second_derivative(border_left) > 0;
    for (double current_point = border_left; current_point <= border_right; current_point += dx) {
        bool derivative_xi_sign = function_data->f_derivative(current_point) > 0;
        bool second_derivative_xi_sign = function_data->f_second_derivative(current_point) > 0;
        if (derivative_sign != derivative_xi_sign) {
            return DERIVATIVE_MUST_BE_SAME_SIGN;
        }
        if (second_derivative_sign != second_derivative_xi_sign) {
            return SECOND_DERIVATIVE_MUST_BE_SAME_SIGN;
        }
    }
    return METHOD_CAN_BE_APPLIED;
}

CSecantResult CSecantMethod::performMethod(CFunctionSV* function_data, double initial_border_left, double initial_border_right, double eps) {
    CDouble border_left = initial_border_left;
    CDouble border_right = initial_border_right;
    SingleFunctionMethodData initial_data(function_data, border_left, border_right, eps);
    MethodResult validation_result = validateBorder(function_data, border_left, border_right);
    CSecantResult result = *new CSecantResult(validation_result, initial_data);
    if (result.getMethodResult() == METHOD_CAN_BE_APPLIED) {
        vector<CDouble> xs;
        CDouble epsilon = (border_right - border_left) / DELTA;
        if (function_data->f(border_left) * function_data->f_second_derivative(border_left) > 0) {
            xs.emplace_back(border_left);
            xs.emplace_back(border_left + epsilon);
        } else {
            xs.emplace_back(border_right);
            xs.emplace_back(border_right - epsilon);
        }
        for (size_t current_iteration = 0; current_iteration < LIMIT_OF_ITERATIONS; current_iteration++) {
            CDouble x_prev = xs[current_iteration + 1];
            CDouble x_prev_prev = xs[current_iteration];
            CDouble x_current = x_prev - function_data->f(x_prev) * (x_prev - x_prev_prev) / (function_data->f(x_prev) - function_data->f(x_prev_prev));
            xs.push_back(x_current);
            if (abs(function_data->f(x_current)) < eps) break;
        }
        for (size_t i = 0; i < xs.size() - 2; i++) {
            result.append(xs[i], xs[i + 1], xs[i + 2]);
        }
        result.setMethodResult(METHOD_WAS_SUCCESSFULLY_FINISHED);
    }
    return result;
}