//
// Created by R1300-W-8-Stud on 16.03.2023.
//

#include "SimpsonMethod.h"

SimpsonMethodResult SimpsonMethod::performIteration(CFunctionSV* f, float a, float b, size_t number_of_intervals) {
    float square = (f->f(a) + f->f(b));
    float dx = (b - a) / (float) number_of_intervals;
    for (size_t i = 1; i < number_of_intervals; i++) {
        square += f->f(a + dx * i) * ((i % 2 == 0) ? 2.0 : 4.0);
    }
    return { dx * square / 3 };
}

SimpsonMethodResult SimpsonMethod::perform(CFunctionSV* f, float a, float b, float eps, size_t number_of_intervals) {
    SingleFunctionMethodData method_data(f, a, b);
    SimpsonMethodResult prev_iteration_result = performIteration(f, a, b, number_of_intervals);
    SimpsonMethodResult curr_iteration_result;
    CVector<CFloat> squares;
    CVector<CSize> intervals;
    squares.push_back(prev_iteration_result.getSquare());
    intervals.push_back(number_of_intervals);
    for (size_t i = 0; i < LIMIT_OF_ITERATIONS; i++) {
        curr_iteration_result = performIteration(f, a, b, 2 * number_of_intervals);
        squares.push_back(curr_iteration_result.getSquare());
        intervals.push_back(number_of_intervals * 2);
        number_of_intervals *= 2;
        if (abs(curr_iteration_result.getSquare() - prev_iteration_result.getSquare()) <= eps) {
            return SimpsonMethodResult(squares, intervals, method_data);
        }
        prev_iteration_result = curr_iteration_result;
    }
    return SimpsonMethodResult(squares, intervals, method_data);
}
