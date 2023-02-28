//
// Created by artem on 23.02.2023.
//

#include "cmath"
#include <conio.h>
#include <fstream>
#include "Lab2.h"

#define KEY_ESC 27

FILE* Lab2::gnu_pipe;

void Lab2::runFromKeyboard() {

    ofstream fs;
    Lab2::gnu_pipe = _popen("gnuplot -persist", "w");

    CFunctionManager manager = CFunctionManager();

    cout << "Welcome to keyboard mode. Default output - stdout. Choose action: ";
    ostream* os = &cout;

    while (true) {
        system("cls");
        cout << "[1] - Perform half-dividing method" << endl;
        cout << "[2] - Perform secant method" << endl;
        cout << "[3] - Perform method of simple iterations" << endl;
        cout << "[4] - Newton method" << endl;
        cout << "[9] - Change output" << endl;
        cout << "[ESC] - Exit" << endl;
        int32_t key = getch();
        system("cls");
        if (key == KEY_ESC) {
            cout << "Good bye." << endl;
            break;
        }
        else if (key == '1') {
            cout << "Half-dividing method" << endl;
            SingleFunctionMethodData data = Lab2::inputDataSingleFunction(manager);
            CHalfDividingResult result = CHalfDividingMethod::performMethod(data.getF(), data.getA(), data.getB(), data.getEps());
            outputResult(*os, result, data.getF(), data.getA(), data.getB());
            cout << "Completed. Press any key to continue...";
        } else if (key == '2') {
            cout << "Secant method" << endl;
            SingleFunctionMethodData data = Lab2::inputDataSingleFunction(manager);
            CSecantResult result = CSecantMethod::performMethod(data.getF(), data.getA(), data.getB(), data.getEps());
            outputResult(*os, result, data.getF(), data.getA(), data.getB());
            cout << "Completed. Press any key to continue...";
        } else if (key == '3') {
            cout << "Method of simple iterations" << endl;
            SingleFunctionMethodData data = Lab2::inputDataSingleFunction(manager);
            CIterationsResult result = CIterationsMethod::performMethod(data.getF(), data.getA(), data.getB(), data.getEps());
            outputResult(*os, result, data.getF(), data.getA(), data.getB());
            cout << "Completed. Press any key to continue...";
        } else if (key == '4') {
            cout << "Newton method" << endl;
            MultipleFunctionMethodData data = Lab2::inputDataMultipleFunction(manager);
            CNewtonResult result = CNewtonMethod::performMethod(data.getF(), data.getG(), data.getA(), data.getB(),data.getEps());
            outputResult(*os, result, data.getF(), data.getG());
            cout << "Completed. Press any key to continue...";
        } else if (key == '9') {
            system("cls");
            cout << "[1] - stdout" << endl;
            cout << "[2] - stderr" << endl;
            cout << "[3] - file from SOURCE_PATH env variable" << endl;
            int32_t key1 = getch();
            if (key1 == '1') {
                os = &cout;
                cout << "Successfully changed" << endl;
            } else if (key1 == '2') {
                os = &cerr;
                cout << "Successfully changed" << endl;
            } else if (key1 == '3') {
                string file_path = std::getenv(ENV_PATH);
                if (file_path.empty()) {
                    cerr << "Not found env. variable '" << ENV_PATH << "'" << endl;
                    return;
                }
                fs.open(std::getenv(ENV_PATH));
                if (fs.fail()) {
                    cerr << "File not found. Make sure that it exists" << endl;
                    return;
                }
                os = &fs;
                cout << "Successfully changed" << endl;
            } else {
                cout << "There is no such key. Press any key to continue...";
            }
        } else {
            cout << "Wrong key. Press any key to continue...";
        }
        getch();
    }

    fclose(Lab2::gnu_pipe);

}

void Lab2::runFromFile() {

}

void Lab2::outputResult(ostream& os, CHalfDividingResult &result, CFunctionSV *function_data, float a, float b) {

    enum MethodResult method_result = result.getMethodResult();
    if (method_result == METHOD_WAS_SUCCESSFULLY_FINISHED) {
        os << "Method was successfully found solution for equation" << endl;
    } else if (method_result == WRONG_NUMBER_OF_SOLUTIONS) {
        os << "There are either no solutions or more than one" << endl;
        return;
    } else if (method_result == DERIVATIVE_MUST_BE_SAME_SIGN) {
        os << "The derivative must be the same sign on given interval" << endl;
        return;
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

    if (&os == &cout) {
        GraphicManager::drawSingleX(gnu_pipe, function_data, a, b);
    }

}


void Lab2::outputResult(ostream& os, CSecantResult &result, CFunctionSV *function_data, float a, float b) {

    enum MethodResult method_result = result.getMethodResult();
    if (method_result == METHOD_WAS_SUCCESSFULLY_FINISHED) {
        os << "Method was successfully found solution for equation" << endl;
    } else if (method_result == WRONG_NUMBER_OF_SOLUTIONS) {
        os << "There are either no solutions or more than one" << endl;
        return;
    } else if (method_result == DERIVATIVE_MUST_BE_SAME_SIGN) {
        os << "The derivative must be the same sign on given interval" << endl;
        return;
    } else if (method_result == SECOND_DERIVATIVE_MUST_BE_SAME_SIGN) {
        os << "The second derivative must be the same sign on given interval" << endl;
        return;
    }
    os << "Number of iterations: " << result.getCountOfIterations() << endl;

    CVector<CFloat> x = result.getX();
    CVector<CFloat> y = result.getY();
    CVector<CFloat> z = result.getZ();

    CTable table(x.n);
    table.insert("x_{i-1}", x);
    table.insert("x_{i}", y);
    table.insert("x_{i+1}", z);
    table.insert("f(x_{i+1})", z.apply(function_data->f));
    table.insert("|x_{i+1} - x_{i}|", (z - y).apply(abs));
    os << table << endl;

    if (&os == &cout) {
        GraphicManager::drawSingleX(gnu_pipe, function_data, a, b);
    }

}


void Lab2::outputResult(ostream& os, CIterationsResult &result, CFunctionSV *function_data, float a, float b) {

    enum MethodResult method_result = result.getMethodResult();
    if (method_result == METHOD_WAS_SUCCESSFULLY_FINISHED) {
        os << "Method was successfully found solution for equation" << endl;
    } else if (method_result == WRONG_NUMBER_OF_SOLUTIONS) {
        os << "There are either no solutions or more than one" << endl;
        return;
    } else if (method_result == DERIVATIVE_MUST_BE_SAME_SIGN) {
        os << "The derivative must be the same sign on given interval" << endl;
        return;
    } else if (method_result == SECOND_DERIVATIVE_MUST_BE_SAME_SIGN) {
        os << "The second derivative must be the same sign on given interval" << endl;
        return;
    } else if (method_result == LIPSCHITZ_CONSTANT_GREATER_THAN_ONE) {
        os << "The derivative of phi must be less then one on interval" << endl;
        return;
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

    if (&os == &cout) {
        GraphicManager::drawMultipleX(gnu_pipe, function_data, a, b);
    }

}

void Lab2::outputResult(ostream& os, CNewtonResult &result, CFunctionMV *f, CFunctionMV *g) {

    enum MethodResult method_result = result.getMethodResult();
    if (method_result == METHOD_WAS_SUCCESSFULLY_FINISHED) {
        os << "Method was successfully found solution for equation" << endl;
    } else if (method_result == WRONG_NUMBER_OF_SOLUTIONS) {
        os << "There are either no solutions or more than one" << endl;
        return;
    } else if (method_result == DERIVATIVE_MUST_BE_SAME_SIGN) {
        os << "The derivative must be the same sign on given interval" << endl;
        return;
    } else if (method_result == SECOND_DERIVATIVE_MUST_BE_SAME_SIGN) {
        os << "The second derivative must be the same sign on given interval" << endl;
        return;
    } else if (method_result == LIPSCHITZ_CONSTANT_GREATER_THAN_ONE) {
        os << "The derivative of phi must be less then one on interval" << endl;
        return;
    }
    os << "Number of iterations: " << result.getCountOfIterations() << endl;

    CVector<CFloat> x = result.getX();
    CVector<CFloat> y = result.getY();
    CVector<CFloat> dx = result.getDX();
    CVector<CFloat> dy = result.getDY();

    CTable table(x.n);
    table.insert("x_{i}", x);
    table.insert("y_{i}", y);
    table.insert("dx_{i}", dx);
    table.insert("dy_{i}", dy);
    table.insert("f(x_{i}, y_{i})", CVector<CFloat>::apply(&x, &y, f->f));
    table.insert("g(x_{i}, y_{i})", CVector<CFloat>::apply(&x, &y, g->f));
    os << table << endl;

}

SingleFunctionMethodData Lab2::inputDataSingleFunction(CFunctionManager manager) {
    bool chosen_function = false;
    CFunctionSV *current_function = nullptr;
    while (!chosen_function) {
        cout << "Choose function: " << endl;
        for (size_t function_index = 0; function_index < manager[SINGLE_VARIABLE].size(); function_index++) {
            cout << "[" << (function_index + 1) << "] - " << *manager[SINGLE_VARIABLE][function_index].release()
                 << endl;
        }
        size_t index = getch() - '1';
        if (index >= 0 && index < 10 && index < manager[SINGLE_VARIABLE].size()) {
            current_function = (CFunctionSV *) manager[SINGLE_VARIABLE][index].release();
            chosen_function = true;
            GraphicManager::drawSingleX(gnu_pipe, current_function, -4, 4);
        } else {
            cout << "There is no such function" << endl;
        }
    }

    CFloat a = 0, b = 0, eps = -1;
    cout << "Input a (left border):" << endl;
    cin >> a;
    do {
        cout << "Input b (right border): " << endl;
        cin >> b;
        if (b <= a) {
            cout << "Error! b <= a! One more time" << endl;
        }
    } while (b <= a);
    do {
        cout << "Input epsilon: " << endl;
        cin >> eps;
        if (eps <= 0) {
            cout << "Error! epsilon must be greater than 0" << endl;
        }
    } while (eps <= 0);
    return { current_function, a, b, eps };
}

MultipleFunctionMethodData Lab2::inputDataMultipleFunction(CFunctionManager manager) {
    bool chosen_function = false;
    CFunctionMV *first_function = nullptr;
    CFunctionMV *second_function = nullptr;
    while (!chosen_function) {
        cout << "Choose function #1: " << endl;
        for (size_t function_index = 0; function_index < manager[TWO_VARIABLES].size(); function_index++) {
            cout << "[" << (function_index + 1) << "] " << * manager[TWO_VARIABLES][function_index].release() << endl;
        }
        size_t index = getch() - '1';
        if (index >= 0 && index < 10 && index < manager[TWO_VARIABLES].size()) {
            first_function = (CFunctionMV *) manager[TWO_VARIABLES][index].release();
            chosen_function = true;
            GraphicManager::drawSingleXY(gnu_pipe, first_function);
        } else {
            cout << "There is no such function" << endl;
        }
    }
    chosen_function = false;
    while (!chosen_function) {
        cout << "Choose function #2: " << endl;
        for (size_t function_index = 0; function_index < manager[TWO_VARIABLES].size(); function_index++) {
            cout << "[" << (function_index + 1) << "] " << *manager[TWO_VARIABLES][function_index].release() << endl;
        }
        size_t index = getch() - '1';
        if (index >= 0 && index < 10 && index < manager[TWO_VARIABLES].size()) {
            second_function = (CFunctionMV *) manager[TWO_VARIABLES][index].release();
            if (first_function == second_function) {
                second_function = nullptr;
                cout << "You already choose this function" << endl;
            } else {
                chosen_function = true;
                GraphicManager::drawMultipleXY(gnu_pipe, first_function, second_function);
            }
        } else {
            cout << "There is no such function" << endl;
        }
    }
    CFloat a = 0, b = 0, eps = -1;
    cout << "Input initial x:" << endl;
    cin >> a;
    cout << "Input y: " << endl;
    cin >> b;
    do {
        cout << "Input epsilon: " << endl;
        cin >> eps;
        if (eps <= 0) {
            cout << "Error! epsilon must be greater than 0" << endl;
        }
    } while (eps <= 0);

    return { first_function, second_function, a, b, eps };
}
