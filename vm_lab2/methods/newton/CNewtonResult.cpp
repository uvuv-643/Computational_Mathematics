//
// Created by artem on 26.02.2023.
//

#include "CNewtonResult.h"

CNewtonResult::CNewtonResult() {
    this->count_of_iterations = 0;
    this->x = *(new CVector<CFloat>(0));
    this->y = *(new CVector<CFloat>(0));
    this->dx = *(new CVector<CFloat>(0));
    this->dy= *(new CVector<CFloat>(0));
    this->method_result = METHOD_WAS_SUCCESSFULLY_FINISHED;
}

CNewtonResult::CNewtonResult(MethodResult method_result) {
    this->method_result = method_result;
}

CSize CNewtonResult::getCountOfIterations() {
    return this->count_of_iterations;
}

enum MethodResult CNewtonResult::getMethodResult() {
    return this->method_result;
}

CVector<CFloat> CNewtonResult::getX() {
    return this->x;
}

CVector<CFloat> CNewtonResult::getY() {
    return this->y;
}

CVector<CFloat> CNewtonResult::getDX() {
    return this->dx;
}

CVector<CFloat> CNewtonResult::getDY() {
    return this->dx;
}

void CNewtonResult::append(CFloat &current_x, CFloat& current_y, CFloat& current_dx, CFloat& current_dy) {
    count_of_iterations++;
    x.push_back(current_x);
    y.push_back(current_y);
    dx.push_back(current_dx);
    dy.push_back(current_dy);
}

void CNewtonResult::setMethodResult(enum MethodResult result) {
    this->method_result = result;
}