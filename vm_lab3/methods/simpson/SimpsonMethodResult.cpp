//
// Created by R1300-W-8-Stud on 16.03.2023.
//

#include "SimpsonMethodResult.h"

SimpsonMethodResult::SimpsonMethodResult() {
    this->status = METHOD_CANNOT_BE_APPLIED;
}

SimpsonMethodResult::SimpsonMethodResult(float square) {
    this->status = ITERATION_WAS_APPLIED;
    this->square = square;
}

SimpsonMethodResult::SimpsonMethodResult(CVector<CFloat> squares, CVector<CSize> number_of_intervals, SingleFunctionMethodData method_data) {
    this->status = METHOD_WAS_APPLIED;
    this->squares = squares;
    this->intervals = number_of_intervals;
    this->method_data = method_data;
}

float SimpsonMethodResult::getSquare() {
    return this->square;
}

CTable SimpsonMethodResult::getResultData() {
    CTable table(intervals.n);
    CVector<CFloat> squares_shifted = (squares);
    squares_shifted.push_front(squares[0]);
    table.insert("n_{i}", intervals);
    table.insert("s_{i}", squares);
    table.insert("eps", (squares - squares_shifted).apply(abs));
    return table;
}