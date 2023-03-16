//
// Created by R1300-W-8-Stud on 16.03.2023.
//

#include "RectMethod.h"

RectMethodResult RectMethod::performIteration(CFunctionSV* f, enum RectMethodType type, float a, float b, size_t number_of_intervals) {
    float square = 0;
    float dx = (b - a) / number_of_intervals;
    for (size_t i = 0; i < number_of_intervals; i++) {
        float target_x;
        switch (type) {
            LEFT_RECTANGULAR: {
                target_x = a + i * dx;
                break;
            }
            RIGHT_RECTANGULAR: {
                target_x = a + (i + 1) * dx;
                break;
            }
            MIDDLE_RECTANGULAR: {
                target_x = a + (i + 0.5) * dx;
                break;
            }
            default: {
                return RectMethodResult();
            }
        }
        square += dx * f->f(target_x);
    }
    return RectMethodResult(square);
}

RectMethodResult RectMethod::perform(CFunctionSV* f, enum RectMethodType type, float a, float b, float eps, size_t number_of_intervals) {
    RectMethodResult prev_iteration_result = performIteration(f, type, a, b, number_of_intervals);
    RectMethodResult curr_iteration_result;
    for (size_t i = 0; i < LIMIT_OF_ITERATIONS; i++) {
        prev_iteration_result = curr_iteration_result;
        curr_iteration_result = performIteration(f, type, a, a, 2 * number_of_intervals);
        number_of_intervals *= 2;
        if (curr_iteration_result.getSquare() - prev_iteration_result.getSquare() <= eps) {
            SingleFunctionMethodData method_data(f, a, b);
            return RectMethodResult(curr_iteration_result.getSquare(), number_of_intervals, method_data);
        }
    }
    return RectMethodResult();
}

