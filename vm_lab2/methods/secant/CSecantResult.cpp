//
// Created by artem on 24.02.2023.
//

#include "CSecantResult.h"

CSecantResult::CSecantResult(SingleFunctionMethodData initial_data) {
    this->count_of_iterations = 0;
    this->x = *(new CVector<CDouble>(0));
    this->y = *(new CVector<CDouble>(0));
    this->z = *(new CVector<CDouble>(0));
    this->method_result = METHOD_WAS_SUCCESSFULLY_FINISHED;
    this->initial_data = initial_data;
}

CSecantResult::CSecantResult(MethodResult method_result, SingleFunctionMethodData initial_data) {
    this->method_result = method_result;
    this->initial_data = initial_data;
}

CSize CSecantResult::getCountOfIterations() {
    return this->count_of_iterations;
}

enum MethodResult CSecantResult::getMethodResult() {
    return this->method_result;
}

CVector<CDouble> CSecantResult::getX() {
    return this->x;
}

CVector<CDouble> CSecantResult::getY() {
    return this->y;
}

CVector<CDouble> CSecantResult::getZ() {
    return this->z;
}

void CSecantResult::append(CDouble &current_x, CDouble& current_y, CDouble& current_z) {
    count_of_iterations++;
    x.push_back(current_x);
    y.push_back(current_y);
    z.push_back(current_z);
}

void CSecantResult::setMethodResult(enum MethodResult result) {
    this->method_result = result;
}

ostream &operator<<(ostream &os, CSecantResult &result) {
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
    }
    os << "Number of iterations: " << result.getCountOfIterations() << endl;

    CVector<CDouble> x = result.getX();
    CVector<CDouble> y = result.getY();
    CVector<CDouble> z = result.getZ();

    CTable table(x.n);
    table.insert("x_{i-1}", x);
    table.insert("x_{i}", y);
    table.insert("x_{i+1}", z);
    table.insert("f(x_{i+1})", z.apply(function_data->f));
    table.insert("|x_{i+1} - x_{i}|", (z - y).apply(abs));
    os << table << endl;

    return os;

}

SingleFunctionMethodData CSecantResult::getInitialData() {
    return this->initial_data;
}