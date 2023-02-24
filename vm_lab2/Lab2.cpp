//
// Created by artem on 23.02.2023.
//

#include "cmath"
#include "Lab2.h"
#include "../data_structures/CTable.cpp"
#include "./methods/half_dividing/CHalfDividingMethod.cpp"
#include "./methods/secant/CSecantMethod.cpp"

float a(float x) {
    return cos(x) - 0.6;
}
float b(float x) {
    return -sin(x);
}
float c(float x) {
    return -cos(x);
}

void Lab2::runFromKeyboard() {
    CHalfDividingResult result = CHalfDividingMethod::performMethod(a, b, 0.5, 1.5, 0.0001);
    outputResult(result, a);

    CSecantResult result1 = CSecantMethod::performMethod(a, b, c, 0.5, 1.5, 0.0001);
    outputResult(result1, a);

}

void Lab2::runFromFile() {

}

void Lab2::outputResult(CHalfDividingResult &result, float f(float)) {

    enum MethodResult method_result = result.getMethodResult();
    cout << method_result << endl;
    if (method_result == METHOD_WAS_SUCCESSFULLY_FINISHED) {
        cout << "Method was successfully found solution for equation" << endl;
    } else if (method_result == WRONG_NUMBER_OF_SOLUTIONS) {
        cout << "There are either no solutions or more than one" << endl;
        return;
    } else if (method_result == DERIVATIVE_MUST_BE_SAME_SIGN) {
        cout << "The derivative must be the same sign on given interval" << endl;
        return;
    }
    cout << "Number of iterations: " << result.getCountOfIterations() << endl;

    CVector<CFloat> answer = result.getAnswers();
    CVector<CFloat> a = result.getA();
    CVector<CFloat> b = result.getB();

    CTable table(answer.n);
    table.insert("a", a);
    table.insert("b", b);
    table.insert("x", answer);
    table.insert("f(a)", a.apply(f));
    table.insert("f(b)", b.apply(f));
    table.insert("f(x)", answer.apply(f));
    table.insert("|a - b|", a - b);
    cout << table << endl;

}


void Lab2::outputResult(CSecantResult &result, float f(float)) {

    enum MethodResult method_result = result.getMethodResult();
    cout << method_result << endl;
    if (method_result == METHOD_WAS_SUCCESSFULLY_FINISHED) {
        cout << "Method was successfully found solution for equation" << endl;
    } else if (method_result == WRONG_NUMBER_OF_SOLUTIONS) {
        cout << "There are either no solutions or more than one" << endl;
        return;
    } else if (method_result == DERIVATIVE_MUST_BE_SAME_SIGN) {
        cout << "The derivative must be the same sign on given interval" << endl;
        return;
    } else if (method_result == SECOND_DERIVATIVE_MUST_BE_SAME_SIGN) {
        cout << "The second derivative must be the same sign on given interval" << endl;
        return;
    }
    cout << "Number of iterations: " << result.getCountOfIterations() << endl;

    CVector<CFloat> x = result.getX();
    CVector<CFloat> y = result.getY();
    CVector<CFloat> z = result.getZ();

    CTable table(x.n);
    table.insert("x_{i-1}", x);
    table.insert("x_{i}", y);
    table.insert("x_{i+1}", z);
    table.insert("f(x_{i+1})", z.apply(f));
    table.insert("|x_{i+1} - x_{i}|", z - y);
    cout << table << endl;

}


