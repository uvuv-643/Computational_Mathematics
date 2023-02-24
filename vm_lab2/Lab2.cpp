//
// Created by artem on 23.02.2023.
//

#include "cmath"
#include "Lab2.h"
#include "../data_structures/CTable.cpp"
#include "./methods/half_dividing/CHalfDividingMethod.cpp"
#include "./methods/secant/CSecantMethod.cpp"
#include "./methods/iterations/CIterationsMethod.cpp"

float a(float x) {
    return pow(x, 3) - x + 4;
}
float b(float x) {
    return 3.0 * pow(x, 2) - 1;
}
float c(float x) {
    return 6 * x;
}
float d(float x) {
    return 12.0 / 11.0 * x - 1.0 / 11.0 * pow(x, 3) - 4.0 / 11.0;
}
float d_derivative(float x) {
    return 12.0 / 11.0 - 3.0 * 1.0 / 11.0 * pow(x, 2);
}

void Lab2::runFromKeyboard() {
    CHalfDividingResult result = CHalfDividingMethod::performMethod(a, b, -2, -1, 0.0001);
    outputResult(result, a);

    CSecantResult result1 = CSecantMethod::performMethod(a, b, c, -2, -1, 0.0001);
    outputResult(result1, a);

    CIterationsResult result2 = CIterationsMethod::performMethod(a, d, d_derivative, -2, -1, 0.0001);
    outputResult(result2, a);

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
    table.insert("|a - b|", (a - b).apply(abs));
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
    table.insert("|x_{i+1} - x_{i}|", (z - y).apply(abs));
    cout << table << endl;

}


void Lab2::outputResult(CIterationsResult &result, float f(float)) {

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
    } else if (method_result == LIPSCHITZ_CONSTANT_GREATER_THAN_ONE) {
        cout << "The derivative of phi must be less then one on interval" << endl;
        return;
    }
    cout << "Number of iterations: " << result.getCountOfIterations() << endl;

    CVector<CFloat> x = result.getX();
    CVector<CFloat> y = result.getY();

    CTable table(x.n);
    table.insert("x_{i-1}", x);
    table.insert("x_{i}", y);
    table.insert("f(x_{i+1})", y.apply(f));
    table.insert("|x_{i+1} - x_{i}|", (y - x).apply(abs));
    cout << table << endl;

}


