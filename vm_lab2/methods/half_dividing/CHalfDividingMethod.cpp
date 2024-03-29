//
// Created by artem on 23.02.2023.
//

#include "CHalfDividingMethod.h"

enum MethodResult CHalfDividingMethod::validateBorder(CFunctionSV* function_data, double border_left, double border_right) {
    if (function_data->f(border_left) * function_data->f(border_right) > 0) {
        return WRONG_NUMBER_OF_SOLUTIONS;
    }
    double dx = (border_right - border_left) / DELTA;
    bool derivative_sign = function_data->f_derivative(border_left) > 0;
    for (double current_point = border_left; current_point <= border_right; current_point += dx) {
        bool derivative_xi_sign = function_data->f_derivative(current_point) > 0;
        if (derivative_sign != derivative_xi_sign) {
            return DERIVATIVE_MUST_BE_SAME_SIGN;
        }
    }
    return METHOD_CAN_BE_APPLIED;
}

CHalfDividingResult CHalfDividingMethod::performMethod(CFunctionSV* function_data, double initial_border_left, double initial_border_right, double eps) {
    CDouble border_left = initial_border_left;
    CDouble border_right = initial_border_right;
    SingleFunctionMethodData initial_data(function_data, border_left, border_right, eps);
    MethodResult validation_result = validateBorder(function_data, border_left, border_right);
    CHalfDividingResult result = *new CHalfDividingResult(validation_result, initial_data);
    if (result.getMethodResult() == METHOD_CAN_BE_APPLIED) {
        do {
            CDouble new_border = (border_right + border_left) / 2;
            result.append(new_border, border_left, border_right);
            if (function_data->f(border_left) * function_data->f(new_border) < 0) {
                border_right = new_border;
            } else if (function_data->f(border_right) * function_data->f(new_border) < 0) {
                border_left = new_border;
            } else if (function_data->f(new_border) == 0) {
                return result;
            } else {
                return *new CHalfDividingResult(WRONG_NUMBER_OF_SOLUTIONS, initial_data);
            }
        } while (result.getCountOfIterations() < LIMIT_OF_ITERATIONS && 2 * (border_right - border_left) > eps);
        result.setMethodResult(METHOD_WAS_SUCCESSFULLY_FINISHED);
    }
    return result;
}