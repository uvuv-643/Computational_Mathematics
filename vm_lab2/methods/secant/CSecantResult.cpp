//
// Created by artem on 24.02.2023.
//

#include "CSecantResult.h"

CSecantResult::CSecantResult() {
    this->count_of_iterations = 0;
    this->x = *(new CVector<CFloat>(0));
    this->y = *(new CVector<CFloat>(0));
    this->z = *(new CVector<CFloat>(0));
    this->method_result = METHOD_WAS_SUCCESSFULLY_FINISHED;
}

CSecantResult::CSecantResult(MethodResult method_result) {
    this->method_result = method_result;
}

CSize CSecantResult::getCountOfIterations() {
    return this->count_of_iterations;
}

enum MethodResult CSecantResult::getMethodResult() {
    return this->method_result;
}

CVector<CFloat> CSecantResult::getX() {
    return this->x;
}

CVector<CFloat> CSecantResult::getY() {
    return this->y;
}

CVector<CFloat> CSecantResult::getZ() {
    return this->z;
}

void CSecantResult::append(CFloat &current_x, CFloat& current_y, CFloat& current_z) {
    count_of_iterations++;
    x.push_back(current_x);
    y.push_back(current_y);
    z.push_back(current_z);
}

void CSecantResult::setMethodResult(enum MethodResult result) {
    this->method_result = result;
}