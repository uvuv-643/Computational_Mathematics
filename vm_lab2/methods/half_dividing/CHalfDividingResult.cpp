//
// Created by artem on 23.02.2023.
//

#include "CHalfDividingResult.h"

CHalfDividingResult::CHalfDividingResult() {
    this->count_of_iterations = 0;
    this->answers = *(new CVector<CFloat>(0));
    this->a = *(new CVector<CFloat>(0));
    this->b = *(new CVector<CFloat>(0));
    this->method_result = METHOD_CAN_BE_APPLIED;
}

CHalfDividingResult::CHalfDividingResult(MethodResult method_result) {
    this->method_result = method_result;
}

CSize CHalfDividingResult::getCountOfIterations() {
    return this->count_of_iterations;
}

enum MethodResult CHalfDividingResult::getMethodResult() {
    return this->method_result;
}

CVector<CFloat> CHalfDividingResult::getA() {
    return this->a;
}

CVector<CFloat> CHalfDividingResult::getB() {
    return this->b;
}

CVector<CFloat> CHalfDividingResult::getAnswers() {
    return this->answers;
}

void CHalfDividingResult::append(CFloat &iteration_answer, CFloat& current_a, CFloat& current_b) {
    count_of_iterations++;
    answers.push_back(iteration_answer);
    a.push_back(current_a);
    b.push_back(current_b);
}

void CHalfDividingResult::setMethodResult(enum MethodResult result) {
    this->method_result = result;
}

