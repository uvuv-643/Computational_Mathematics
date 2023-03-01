//
// Created by artem on 23.02.2023.
//

#include "CHalfDividingResult.h"

CHalfDividingResult::CHalfDividingResult(SingleFunctionMethodData initial_data) {
    this->count_of_iterations = 0;
    this->answers = *(new CVector<CFloat>(0));
    this->a = *(new CVector<CFloat>(0));
    this->b = *(new CVector<CFloat>(0));
    this->method_result = METHOD_CAN_BE_APPLIED;
    this->initial_data = initial_data;
}

CHalfDividingResult::CHalfDividingResult(MethodResult method_result, SingleFunctionMethodData initial_data) {
    this->method_result = method_result;
    this->initial_data = initial_data;
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

ostream &operator<<(ostream &os, CHalfDividingResult &result) {
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
    }
    os << "Number of iterations: " << result.getCountOfIterations() << endl;

    CVector<CFloat> answer = result.getAnswers();
    CVector<CFloat> aRow = result.getA();
    CVector<CFloat> bRow = result.getB();

    CTable table(answer.n);
    table.insert("a", aRow);
    table.insert("b", bRow);
    table.insert("x", answer);
    table.insert("f(a)", aRow.apply(function_data->f));
    table.insert("f(b)", bRow.apply(function_data->f));
    table.insert("f(x)", answer.apply(function_data->f));
    table.insert("|a - b|", (aRow - bRow).apply(abs));
    os << table << endl;

    return os;
}

SingleFunctionMethodData CHalfDividingResult::getInitialData() {
    return this->initial_data;
}


