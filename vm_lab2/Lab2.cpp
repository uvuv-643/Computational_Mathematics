//
// Created by artem on 23.02.2023.
//

#include "cmath"
#include <conio.h>
#include <fstream>
#include "Lab2.h"

#define KEY_ESC 27

FILE *Lab2::gnu_pipe;

void Lab2::runFromKeyboard() {

    ofstream fs;
    Lab2::gnu_pipe = _popen("gnuplot -persist", "w");

    CFunctionManager manager = CFunctionManager();

    cout << "Welcome to keyboard mode. Default output - stdout. Choose action: ";
    ostream *os = &cout;

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
        } else if (key == '1') {
            cout << "Half-dividing method" << endl;
            SingleFunctionMethodData data = Lab2::inputDataSingleFunction(manager);
            CHalfDividingResult result = CHalfDividingMethod::performMethod(data.getF(), data.getA(), data.getB(),data.getEps());
            (*os) << result;
            if (os == &cout) {
                GraphicManager::drawSingleX(gnu_pipe, data.getF(), data.getA(), data.getB());
            }
            cout << "Completed. Press any key to continue...";
        } else if (key == '2') {
            cout << "Secant method" << endl;
            SingleFunctionMethodData data = Lab2::inputDataSingleFunction(manager);
            CSecantResult result = CSecantMethod::performMethod(data.getF(), data.getA(), data.getB(), data.getEps());
            (*os) << result;
            if (os == &cout) {
                GraphicManager::drawSingleX(gnu_pipe, data.getF(), data.getA(), data.getB());
            }
            cout << "Completed. Press any key to continue...";
        } else if (key == '3') {
            cout << "Method of simple iterations" << endl;
            SingleFunctionMethodData data = Lab2::inputDataSingleFunction(manager);
            CIterationsResult result = CIterationsMethod::performMethod(data.getF(), data.getA(), data.getB(),
                                                                        data.getEps());
            (*os) << result;
            if (os == &cout) {
                GraphicManager::drawMultipleX(gnu_pipe, data.getF(), data.getA(), data.getB());
            }
            cout << "Completed. Press any key to continue...";
        } else if (key == '4') {
            cout << "Newton method" << endl;
            MultipleFunctionMethodData data = Lab2::inputDataMultipleFunction(manager);
            CNewtonResult result = CNewtonMethod::performMethod(data.getF(), data.getG(), data.getA(), data.getB(),
                                                                data.getEps());
            (*os) << result;
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
    CFunctionManager manager = CFunctionManager();
    string file_path = std::getenv(ENV_PATH);
    if (file_path.empty()) {
        cerr << "Not found env. variable '" << ENV_PATH << "'" << endl;
        return;
    }
    ifstream fs;
    fs.open(std::getenv(ENV_PATH));
    if (fs.fail()) {
        cerr << "File not found. Make sure that it exists" << endl;
        return;
    }
    CSize type;
    fs >> type;
    if (type == 1) {
        CFloat a, b, eps;
        CSize number_of_method, number_of_function;
        fs >> number_of_method >> number_of_function >> a >> b >> eps;
        if (number_of_method > 0 && (int32_t) number_of_method <= 3) {
            if (a >= b) {
                cerr << "Incorrect #a, #b" << endl;
                return;
            }
            if (eps <= 0) {
                cerr << "Incorrect #eps" << endl;
                return;
            }
            CFunctionSV *current_function = nullptr;
            size_t index = (size_t) number_of_function - 1;
            if (index >= 0 && index < 10 && index < manager[SINGLE_VARIABLE].size()) {
                current_function = (CFunctionSV *) manager[SINGLE_VARIABLE][index].release();
            } else {
                cout << "There is no such function" << endl;
            }
            if (number_of_method == 1) {
                cout << "Half-dividing method" << endl;
                SingleFunctionMethodData data(current_function, a, b, eps);
                CHalfDividingResult result = CHalfDividingMethod::performMethod(data.getF(), data.getA(), data.getB(),data.getEps());
                cout << result;
                cout << "Completed. Press any key to continue...";
            } else if (number_of_method == 2) {
                cout << "Secant method" << endl;
                SingleFunctionMethodData data(current_function, a, b, eps);
                CSecantResult result = CSecantMethod::performMethod(data.getF(), data.getA(), data.getB(), data.getEps());
                cout << result;
                cout << "Completed. Press any key to continue...";
            } else if (number_of_method == 3) {
                cout << "Method of simple iterations" << endl;
                SingleFunctionMethodData data(current_function, a, b, eps);
                CIterationsResult result = CIterationsMethod::performMethod(data.getF(), data.getA(), data.getB(),data.getEps());
                cout << result;
                cout << "Completed. Press any key to continue...";
            }
        } else {
            cerr << "Incorrect #number_of_method" << endl;
        }
    } else if (type == 2) {
        CFunctionMV *first_function = nullptr;
        CFunctionMV *second_function = nullptr;
        CFloat x, y, eps;
        CSize f, g;
        fs >> f >> g >> x >> y >> eps;
            if (eps <= 0) {
                cerr << "Incorrect #eps" << endl;
                return;
            }
        size_t index1 = (size_t) f - 1;
        size_t index2 = (size_t) g - 1;
        if (index1 >= 0 && index1 < 10 && index1 < manager[TWO_VARIABLES].size() && index2 >= 0 && index2 < 10 && index1 < manager[TWO_VARIABLES].size()) {
            first_function = (CFunctionMV *) manager[TWO_VARIABLES][index1].release();
            second_function = (CFunctionMV *) manager[TWO_VARIABLES][index2].release();
            if (first_function == second_function) {
                second_function = nullptr;
                cout << "You choose the same functions" << endl;
            }
        } else {
            cout << "There is no such function" << endl;
        }

        cout << "Newton method" << endl;
        MultipleFunctionMethodData data = MultipleFunctionMethodData(first_function, second_function, x, y, eps);
        CNewtonResult result = CNewtonMethod::performMethod(data.getF(), data.getG(), data.getA(), data.getB(),data.getEps());
        cout << result;
        cout << "Completed. Press any key to continue...";

    } else {
        cerr << "Incorrect file" << endl;
    }

    getch();

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
    return {current_function, a, b, eps};
}

MultipleFunctionMethodData Lab2::inputDataMultipleFunction(CFunctionManager manager) {
    bool chosen_function = false;
    CFunctionMV *first_function = nullptr;
    CFunctionMV *second_function = nullptr;
    while (!chosen_function) {
        cout << "Choose function #1: " << endl;
        for (size_t function_index = 0; function_index < manager[TWO_VARIABLES].size(); function_index++) {
            cout << "[" << (function_index + 1) << "] " << *manager[TWO_VARIABLES][function_index].release() << endl;
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

    return {first_function, second_function, a, b, eps};
}
