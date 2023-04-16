//
// Created by artem on 26.02.2023.
//

#include "CNewtonResult.h"

CNewtonResult::CNewtonResult(MultipleFunctionMethodData initial_data) {
    this->count_of_iterations = 0;
    this->x = *(new CVector<CDouble>(0));
    this->y = *(new CVector<CDouble>(0));
    this->dx = *(new CVector<CDouble>(0));
    this->dy= *(new CVector<CDouble>(0));
    this->method_result = METHOD_WAS_SUCCESSFULLY_FINISHED;
    this->initial_data = initial_data;
}

CNewtonResult::CNewtonResult(MethodResult method_result, MultipleFunctionMethodData initial_data) {
    this->method_result = method_result;
    this->initial_data = initial_data;
}

CSize CNewtonResult::getCountOfIterations() {
    return this->count_of_iterations;
}

enum MethodResult CNewtonResult::getMethodResult() {
    return this->method_result;
}

CVector<CDouble> CNewtonResult::getX() {
    return this->x;
}

CVector<CDouble> CNewtonResult::getY() {
    return this->y;
}

CVector<CDouble> CNewtonResult::getDX() {
    return this->dx;
}

CVector<CDouble> CNewtonResult::getDY() {
    return this->dx;
}

void CNewtonResult::append(CDouble &current_x, CDouble& current_y, CDouble& current_dx, CDouble& current_dy) {
    count_of_iterations++;
    x.push_back(current_x);
    y.push_back(current_y);
    dx.push_back(current_dx);
    dy.push_back(current_dy);
}

void CNewtonResult::setMethodResult(enum MethodResult result) {
    this->method_result = result;
}

ostream &operator<<(ostream &os, CNewtonResult &result) {

    MultipleFunctionMethodData initial_data = result.getInitialData();
    CFunctionMV* f = initial_data.getF();
    CFunctionMV* g = initial_data.getG();

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

    CVector<CDouble> x = result.getX();
    CVector<CDouble> y = result.getY();
    CVector<CDouble> dx = result.getDX();
    CVector<CDouble> dy = result.getDY();

    CTable table(x.n);
    table.insert("x_{i}", x);
    table.insert("y_{i}", y);
    table.insert("dx_{i}", dx);
    table.insert("dy_{i}", dy);
    table.insert("f(x_{i}, y_{i})", CVector<CDouble>::apply(&x, &y, f->f));
    table.insert("g(x_{i}, y_{i})", CVector<CDouble>::apply(&x, &y, g->f));
    os << table << endl;

    return os;

}

MultipleFunctionMethodData CNewtonResult::getInitialData() {
    return this->initial_data;
}
