//
// Created by artem on 23.02.2023.
//

#include "CHalfDividingMethod.h"


enum MethodResult CHalfDividingMethod::validateBorder(float f(float), float derivative(float), float border_left, float border_right) {
    if (f(border_left) * f(border_right) > 0) {
        return WRONG_NUMBER_OF_SOLUTIONS;
    }
    float dx = (border_right - border_left) / DELTA;
    bool derivative_sign = derivative(border_left) > 0;
    for (float current_point = border_left; current_point <= border_right; current_point += dx) {
        bool derivative_xi_sign = derivative(current_point) > 0;
        if (derivative_sign != derivative_xi_sign) {
            return DERIVATIVE_MUST_BE_SAME_SIGN;
        }
    }
    return METHOD_CAN_BE_APPLIED;
}

CHalfDividingResult CHalfDividingMethod::performMethod(float f(float), float derivative(float), float initial_border_left, float initial_border_right, float eps) {
    CFloat border_left = initial_border_left;
    CFloat border_right = initial_border_right;
    CHalfDividingResult result = *new CHalfDividingResult(validateBorder(f, derivative, border_left, border_right));
    if (result.getMethodResult() == METHOD_CAN_BE_APPLIED) {
        do {
            CFloat new_border = (border_right + border_left) / 2;
            result.append(new_border, border_left, border_right);
            if (f(border_left) * f(new_border) < 0) {
                border_right = new_border;
            } else if (f(border_right) * f(new_border) < 0) {
                border_left = new_border;
            } else if (f(new_border) == 0) {
                return result;
            } else {
                return *new CHalfDividingResult(WRONG_NUMBER_OF_SOLUTIONS);
            }
        } while (result.getCountOfIterations() < LIMIT_OF_ITERATIONS && 2 * (border_right - border_left) > eps);
        result.setMethodResult(METHOD_WAS_SUCCESSFULLY_FINISHED);
    }
    return result;
}