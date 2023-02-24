//
// Created by artem on 24.02.2023.
//

#include "CSecantMethod.h"

enum MethodResult CSecantMethod::validateBorder(float f(float), float derivative(float), float second_derivative(float), float border_left, float border_right) {
    if (f(border_left) * f(border_right) > 0) {
        return WRONG_NUMBER_OF_SOLUTIONS;
    }
    float dx = (border_right - border_left) / DELTA;
    bool derivative_sign = derivative(border_left) > 0;
    bool second_derivative_sign = second_derivative(border_left) > 0;
    for (float current_point = border_left; current_point <= border_right; current_point += dx) {
        bool derivative_xi_sign = derivative(current_point) > 0;
        bool second_derivative_xi_sign = second_derivative(current_point) > 0;
        if (derivative_sign != derivative_xi_sign) {
            return DERIVATIVE_MUST_BE_SAME_SIGN;
        }
        if (second_derivative_sign != second_derivative_xi_sign) {
            return SECOND_DERIVATIVE_MUST_BE_SAME_SIGN;
        }
    }
    return METHOD_CAN_BE_APPLIED;
}

CSecantResult CSecantMethod::performMethod(float f(float), float derivative(float), float second_derivative(float), float initial_border_left, float initial_border_right, float eps) {
    CFloat border_left = initial_border_left;
    CFloat border_right = initial_border_right;
    CSecantResult result = *new CSecantResult(validateBorder(f, derivative, second_derivative, border_left, border_right));
    if (result.getMethodResult() == METHOD_CAN_BE_APPLIED) {
        vector<CFloat> xs;
        CFloat epsilon = (border_right - border_left) / DELTA;
        if (f(border_left) * second_derivative(border_left) > 0) {
            xs.emplace_back(border_left);
            xs.emplace_back(border_left + epsilon);
        } else {
            xs.emplace_back(border_right);
            xs.emplace_back(border_right - epsilon);
        }
        for (size_t current_iteration = 0; current_iteration < LIMIT_OF_ITERATIONS; current_iteration++) {
            CFloat x_prev = xs[current_iteration + 1];
            CFloat x_prev_prev = xs[current_iteration];
            CFloat x_current = x_prev - f(x_prev) * (x_prev - x_prev_prev) / (f(x_prev) - f(x_prev_prev));
            xs.push_back(x_current);
            if (abs(f(x_current)) < eps) break;
        }
        for (size_t i = 0; i < xs.size() - 2; i++) {
            result.append(xs[i], xs[i + 1], xs[i + 2]);
        }
        result.setMethodResult(METHOD_WAS_SUCCESSFULLY_FINISHED);
    }
    return result;
}

void CSecantResult::setMethodResult(enum MethodResult result) {
    this->method_result = result;
}