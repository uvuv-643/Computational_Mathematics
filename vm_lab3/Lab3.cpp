//
// Created by R1300-W-8-Stud on 16.03.2023.
//

#include "Lab3.h"

#define KEY_ESC 27

FILE *Lab3::gnu_pipe;

void Lab3::runFromKeyboard() {

    ofstream fs;
    Lab3::gnu_pipe = _popen("gnuplot -persist", "w");

    CFunctionManager manager = CFunctionManager();

    cout << "Welcome to keyboard mode. Default output - stdout. Choose action: ";
    ostream *os = &cout;

    while (true) {
        system("cls");
        cout << "[1] - Perform left-rectangle method" << endl;
        cout << "[2] - Perform right-rectangle method" << endl;
        cout << "[3] - Perform middle-rectangle method" << endl;
        cout << "[4] - Perform trapeze method" << endl;
        cout << "[5] - Perform Simpson method" << endl;
        cout << "[9] - Change output" << endl;
        cout << "[ESC] - Exit" << endl;
        int32_t key = getch();
        system("cls");
        if (key == KEY_ESC) {
            cout << "Good bye." << endl;
            break;
        } else if (key == '1') {
            cout << "Left-rectangle method" << endl;
            SingleFunctionIntegralMethodData data = Lab3::inputDataSingleFunction(manager);
            RectMethodResult result = RectMethod::perform(data.getF(),LEFT_RECTANGULAR, data.getA(), data.getB(),data.getEps(), 4);
            CTable result_table = result.getResultData();
            (*os) << result_table;
            cout << "Completed. Press any key to continue...";
        } else if (key == '2') {
            cout << "Right-rectangle method" << endl;
            SingleFunctionIntegralMethodData data = Lab3::inputDataSingleFunction(manager);
            RectMethodResult result = RectMethod::perform(data.getF(),RIGHT_RECTANGULAR, data.getA(), data.getB(),data.getEps(), 4);
            CTable result_table = result.getResultData();
            (*os) << result_table;
            cout << "Completed. Press any key to continue...";
        } else if (key == '3') {
            cout << "Middle-rectangle method" << endl;
            SingleFunctionIntegralMethodData data = Lab3::inputDataSingleFunction(manager);
            RectMethodResult result = RectMethod::perform(data.getF(),MIDDLE_RECTANGULAR, data.getA(), data.getB(),data.getEps(), 4);
            CTable result_table = result.getResultData();
            (*os) << result_table;
            cout << "Completed. Press any key to continue...";
        } else if (key == '4') {
            cout << "Trapeze method" << endl;
            SingleFunctionIntegralMethodData data = Lab3::inputDataSingleFunction(manager);
            TrapezeMethodResult result = TrapezeMethod::perform(data.getF(), data.getA(), data.getB(),data.getEps(), 4);
            CTable result_table = result.getResultData();
            (*os) << result_table;
            cout << "Completed. Press any key to continue...";
        } else if (key == '5') {
            cout << "Simpson method" << endl;
            SingleFunctionIntegralMethodData data = Lab3::inputDataSingleFunction(manager);
            SimpsonMethodResult result = SimpsonMethod::perform(data.getF(), data.getA(), data.getB(),data.getEps(), 4);
            CTable result_table = result.getResultData();
            (*os) << result_table;
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

    fclose(Lab3::gnu_pipe);

}

void Lab3::runFromFile() {
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
    CDouble a, b, eps;
    CSize number_of_method, number_of_function;
    fs >> number_of_method >> number_of_function >> a >> b >> eps;
    if (number_of_method > 0 && (int32_t) number_of_method <= 5) {
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
        if (index >= 0 && index < 10 && index < manager.getSingleFunctions().size()) {
            current_function = (CFunctionSV *) manager.getSingleFunctions()[index];
        } else {
            cout << "There is no such function" << endl;
        }
        if (number_of_method == 1) {
            cout << "Left-rectangle method" << endl;
            SingleFunctionIntegralMethodData data(current_function, a, b, eps);
            RectMethodResult result = RectMethod::perform(data.getF(),LEFT_RECTANGULAR, data.getA(), data.getB(),data.getEps(), 4);
            CTable result_table = result.getResultData();
            cout << result_table;
            cout << "Completed. Press any key to continue...";
        } else if (number_of_method == 2) {
            cout << "Right-rectangle method" << endl;
            SingleFunctionIntegralMethodData data(current_function, a, b, eps);
            RectMethodResult result = RectMethod::perform(data.getF(),RIGHT_RECTANGULAR, data.getA(), data.getB(),data.getEps(), 4);
            CTable result_table = result.getResultData();
            cout << result_table;
            cout << "Completed. Press any key to continue...";
        } else if (number_of_method == 3) {
            cout << "Middle-rectangle method" << endl;
            SingleFunctionIntegralMethodData data(current_function, a, b, eps);
            RectMethodResult result = RectMethod::perform(data.getF(),MIDDLE_RECTANGULAR, data.getA(), data.getB(),data.getEps(), 4);
            CTable result_table = result.getResultData();
            cout << result_table;
            cout << "Completed. Press any key to continue...";
        }  else if (number_of_method == 4) {
            cout << "Trapeze method" << endl;
            SingleFunctionIntegralMethodData data(current_function, a, b, eps);
            TrapezeMethodResult result = TrapezeMethod::perform(data.getF(), data.getA(), data.getB(),data.getEps(), 4);
            CTable result_table = result.getResultData();
            cout << result_table;
            cout << "Completed. Press any key to continue...";
        } else if (number_of_method == 5) {
            cout << "Simpson method" << endl;
            SingleFunctionIntegralMethodData data = Lab3::inputDataSingleFunction(manager);
            SimpsonMethodResult result = SimpsonMethod::perform(data.getF(), data.getA(), data.getB(),data.getEps(), 4);
            CTable result_table = result.getResultData();
            cout << result_table;
            cout << "Completed. Press any key to continue...";
        }
    } else {
        cerr << "Incorrect #number_of_method" << endl;
    }
    getch();
}

SingleFunctionIntegralMethodData Lab3::inputDataSingleFunction(CFunctionManager manager) {
    bool chosen_function = false;
    CFunctionSV *current_function = nullptr;
    while (!chosen_function) {
        cout << "Choose function: " << endl;
        for (size_t function_index = 0; function_index < manager.getSingleFunctions().size(); function_index++) {
            cout << "[" << (function_index + 1) << "] - " << *manager.getSingleFunctions()[function_index]
                 << endl;
        }
        size_t index = getch() - '1';
        if (index >= 0 && index < 10 && index < manager.getSingleFunctions().size()) {
            current_function = (CFunctionSV *) manager.getSingleFunctions()[index];
            chosen_function = true;
            GraphicManager::drawSingleX(gnu_pipe, current_function, -4, 4);
        } else {
            cout << "There is no such function" << endl;
        }
    }

    CDouble a = 0, b = 0, eps = -1;
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
