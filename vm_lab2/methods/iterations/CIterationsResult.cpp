//
// Created by artem on 24.02.2023.
//

#include "CIterationsResult.h"

CIterationsResult::CIterationsResult(SingleFunctionMethodData initial_data) {
    this->count_of_iterations = 0;
    this->x = *(new CVector<CFloat>(0));
    this->y = *(new CVector<CFloat>(0));
    this->method_result = METHOD_WAS_SUCCESSFULLY_FINISHED;
    this->initial_data = initial_data;
}

CIterationsResult::CIterationsResult(MethodResult method_result, SingleFunctionMethodData initial_data) {
    this->method_result = method_result;
    this->initial_data = initial_data;
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

SingleFunctionMethodData CIterationsResult::getInitialData() {
    return this->initial_data;
}

ostream &operator<<(ostream &os, CIterationsResult &result) {
    SingleFunctionMethodData data = result.getInitialData();
    CFunctionSV* function_data = data.getF();

    enum MethodResult method_result = result.getMethodResult();
    if (method_result == METHOD_WAS_SUCCESSFULLY_FINISHED) {
        os << "Method was successfully found solution for equation" << endl;
    } else if (method_result == WRONG_NUMBER_OF_SOLUTIONS) {
        os << "There are either no solutions or more than one" << endl;
        return os;
    } else if (method_result == DERIVATIVE_MUST_BE_SAME_SIGN) {
        os << "The derivative must be the same sign on given interval" << endl;
        return os;
    } else if (method_result == SECOND_DERIVATIVE_MUST_BE_SAME_SIGN) {
        os << "The second derivative must be the same sign on given interval" << endl;
        return os;
    } else if (method_result == LIPSCHITZ_CONSTANT_GREATER_THAN_ONE) {
        os << "The derivative of phi must be less then one on interval" << endl;
        return os;
    }
    os << "Number of iterations: " << result.getCountOfIterations() << endl;

    CVector<CFloat> x = result.getX();
    CVector<CFloat> y = result.getY();

    CTable table(x.n);
    table.insert("x_{i-1}", x);
    table.insert("x_{i}", y);
    table.insert("f(x_{i+1})", y.apply(function_data->f));
    table.insert("|x_{i+1} - x_{i}|", (y - x).apply(abs));
    os << table << endl;

    return os;
}
