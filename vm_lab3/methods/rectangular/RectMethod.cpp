//
// Created by R1300-W-8-Stud on 16.03.2023.
//

#include "RectMethod.h"

RectMethodResult RectMethod::performIteration(CFunctionSV* f, enum RectMethodType type, double a, double b, size_t number_of_intervals) {
    double square = 0;
    double dx = (b - a) / (double) number_of_intervals;
    for (size_t i = 0; i < number_of_intervals; i++) {
        double target_x;
        switch (type) {
            case LEFT_RECTANGULAR: {
                target_x = a + dx * i;
                break;
            }
            case MIDDLE_RECTANGULAR: {
                target_x = a + dx * (i + 0.5);
                break;
            }
            case RIGHT_RECTANGULAR: {
                target_x = a + dx * (i + 1);
                break;
            }
            default: {
                return {};
            }
        }
        square += f->f(target_x);
    }
    return {square * dx};
}

RectMethodResult RectMethod::perform(CFunctionSV* f, enum RectMethodType type, double a, double b, double eps, size_t number_of_intervals) {
    SingleFunctionIntegralMethodData method_data(f, a, b);
    RectMethodResult prev_iteration_result = performIteration(f, type, a, b, number_of_intervals);
    RectMethodResult curr_iteration_result;
    CVector<CDouble> squares;
    CVector<CSize> intervals;
    squares.push_back(prev_iteration_result.getSquare());
    intervals.push_back(number_of_intervals);
    for (size_t i = 0; i < LIMIT_OF_ITERATIONS; i++) {
        prev_iteration_result = curr_iteration_result;
        curr_iteration_result = performIteration(f, type, a, b, 2 * number_of_intervals);
        squares.push_back(curr_iteration_result.getSquare());
        intervals.push_back(number_of_intervals * 2);
        number_of_intervals *= 2;
        if (abs(curr_iteration_result.getSquare() - prev_iteration_result.getSquare()) <= eps) {
            return RectMethodResult(squares, intervals, method_data);
        }
    }
    return RectMethodResult(squares, intervals, method_data);
}

