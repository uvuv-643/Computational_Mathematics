//
// Created by artem on 23.02.2023.
//

#include "cmath"
#include "Lab2.h"
#include "../data_structures/CTable.cpp"
#include "./methods/half_dividing/CHalfDividingMethod.cpp"
#include "./methods/secant/CSecantMethod.cpp"
#include "./methods/iterations/CIterationsMethod.cpp"
#include "functions/CFunctionManager.cpp"
#include "functions/FunctionType.h"


void Lab2::runFromKeyboard() {

    CFunctionManager manager = * new CFunctionManager();
    CFunctionSW* function1 = (CFunctionSW *) (manager[SINGLE_VARIABLE][0].release());

    CHalfDividingResult result = CHalfDividingMethod::performMethod(function1, -2, -1, 0.0001);
    outputResult(result, function1);

    CSecantResult result1 = CSecantMethod::performMethod(function1, -2, -1, 0.0001);
    outputResult(result1, function1);

    CIterationsResult result2 = CIterationsMethod::performMethod(function1, -2, -1, 0.0001);
    outputResult(result2, function1);

}

void Lab2::runFromFile() {

}

void Lab2::outputResult(CHalfDividingResult &result, CFunction* function_data) {

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
    table.insert("f(a)", a.apply(function_data->f));
    table.insert("f(b)", b.apply(function_data->f));
    table.insert("f(x)", answer.apply(function_data->f));
    table.insert("|a - b|", (a - b).apply(abs));
    cout << table << endl;

}


void Lab2::outputResult(CSecantResult &result, CFunction* function_data) {

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
    table.insert("f(x_{i+1})", z.apply(function_data->f));
    table.insert("|x_{i+1} - x_{i}|", (z - y).apply(abs));
    cout << table << endl;

}


void Lab2::outputResult(CIterationsResult &result, CFunction* function_data) {

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
    table.insert("f(x_{i+1})", y.apply(function_data->f));
    table.insert("|x_{i+1} - x_{i}|", (y - x).apply(abs));
    cout << table << endl;

}


