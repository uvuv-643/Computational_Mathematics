//
// Created by artem on 24.02.2023.
//

#include "CIterationsResult.h"

CIterationsResult::CIterationsResult() {
    this->count_of_iterations = 0;
    this->x = *(new CVector<CFloat>(0));
    this->y = *(new CVector<CFloat>(0));
    this->method_result = METHOD_WAS_SUCCESSFULLY_FINISHED;
}

CIterationsResult::CIterationsResult(MethodResult method_result) {
    this->method_result = method_result;
}

CSize CIterationsResult::getCountOfIterations() {
    return this->count_of_iterations;
}

enum MethodResult CIterationsResult::getMethodResult() {
    return this->method_result;
}

CVector<CFloat> CIterationsResult::getX() {
    return this->x;
}

CVector<CFloat> CIterationsResult::getY() {
    return this->y;
}

void CIterationsResult::append(CFloat &current_x, CFloat& current_y) {
    count_of_iterations++;
    x.push_back(current_x);
    y.push_back(current_y);
}

void CIterationsResult::setMethodResult(enum MethodResult result) {
    this->method_result = result;
}