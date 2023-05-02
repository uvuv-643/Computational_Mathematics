//
// Created by artem on 01.05.2023.
//

#include <fstream>
#include "Lab5.h"

FILE *Lab5::gnu_pipe;

void Lab5::runFromKeyboard() {

    Lab5::gnu_pipe = _popen("gnuplot -persist", "w");

    DiscreteFunction df("lab5");
    cin >> df;
    cout << df;

    cout << "Enter x value where you want to calculate result:" << endl;
    CDouble target;
    cin >> target;

    CDouble answer_lg = Lg::performMethod(df, target);
    cout << "Lagrange answer in x_target: " << answer_lg << endl;
    GsMethodResult res = Gs::performMethod(df, target);

    if (res.isSuccess()) {
        cout << "Stirling polynomial answer: :" << St::performMethod(df, target) << endl;
        cout << "Gauss answer in x_target: " << res.getAnswer() << endl;
        CTable fd = res.getFiniteDifferences();
        cout << "Table of finite differences: " << endl;
        cout << fd << endl;
        cout << "Target polynomial function: " << endl;
        cout << res.getFunctionDefinition() << endl;
        CVector<CDouble> tx = df.getX();
        CVector<CDouble> ty = df.getY();
        GraphicManager::drawSingleXWithPoints(gnu_pipe, res.getFunctionDefinition(), tx.data, ty.data, df.getX().min(),
                                              df.getX().max());
    } else {
        cout << "To apply Gauss and Stirling method number of points must be odd" << endl;

    }
}

void Lab5::runFromFunctions() {

    Lab5::gnu_pipe = _popen("gnuplot -persist", "w");
    CFunctionManager functionManager;

    DiscreteFunction df("lab5");
    cout << "Enter function from which you want to generate points? " << endl;
    auto functions = functionManager.getSingleFunctions();
    for (size_t i = 0; i < functions.size(); i++) {
        cout << "[" << i + 1 << "] ";
        cout << functions[i]->function_definition << endl;
    }
    cout << "Enter number of function to generate points" << endl;
    CSize number_of_function;
    while (true) {
        cin >> number_of_function;
        if (number_of_function > 0 && (size_t) number_of_function <= functions.size()) {
            CSize number_of_points;
            CDouble a, b;
            cout << "Enter number of points: " << endl;
            cin >> number_of_points;
            cout << "Enter [a, b]" << endl;
            cin >> a >> b;
            vector<CDouble> x(number_of_points);
            vector<CDouble> y(number_of_points);
            for (size_t i = 0; i < (size_t) number_of_points; i++) {
                x[i] = (double) a + ((b - a) * (double) i) / (double) (size_t) number_of_points;
                y[i] = functions[(size_t) number_of_function - 1]->f(x[i]);
            }
            df.setNumberOfPoints(number_of_points);
            df.setX(CVector<CDouble>(x));
            df.setY(CVector<CDouble>(y));
            break;
        } else {
            cout << "Incorrect number of function" << endl;
        }
    }


    cout << df;

    cout << "Enter x value where you want to calculate result:" << endl;
    CDouble target;
    cin >> target;


    CDouble answer_lg = Lg::performMethod(df, target);
    cout << "Lagrange answer in x_target: " << answer_lg << endl;
    GsMethodResult res = Gs::performMethod(df, target);

    if (res.isSuccess()) {
        cout << "Stirling polynomial answer: :" << St::performMethod(df, target) << endl;
        cout << "Gauss answer in x_target: " << res.getAnswer() << endl;
        CTable fd = res.getFiniteDifferences();
        cout << "Table of finite differences: " << endl;
        cout << fd << endl;
        cout << "Target polynomial function: " << endl;
        cout << res.getFunctionDefinition() << endl;
        CVector<CDouble> tx = df.getX();
        CVector<CDouble> ty = df.getY();
        GraphicManager::drawSingleXWithPoints(gnu_pipe, res.getFunctionDefinition(), tx.data, ty.data, df.getX().min(),
                                              df.getX().max());
    } else {
        cout << "To apply Gauss and Stirling method number of points must be odd" << endl;
    }

}

void Lab5::runFromFile() {

    Lab5::gnu_pipe = _popen("gnuplot -persist", "w");

    string file_path = std::getenv(ENV_PATH_INPUT);
    if (file_path.empty()) {
        cerr << "Not found env. variable '" << ENV_PATH_INPUT << "'" << endl;
        return;
    }
    ifstream fs;
    fs.open(std::getenv(ENV_PATH_INPUT));
    if (fs.fail()) {
        cerr << "File not found. Make sure that it exists" << endl;
        return;
    }

    DiscreteFunction df("lab5");
    fs >> df;
    cout << df;

    CDouble target;
    fs >> target;

    CDouble answer_lg = Lg::performMethod(df, target);
    cout << "Lagrange answer in x_target: " << answer_lg << endl;
    GsMethodResult res = Gs::performMethod(df, target);

    if (res.isSuccess()) {
        cout << "Stirling polynomial answer: :" << St::performMethod(df, target) << endl;
        cout << "Gauss answer in x_target: " << res.getAnswer() << endl;
        CTable fd = res.getFiniteDifferences();
        cout << "Table of finite differences: " << endl;
        cout << fd << endl;
        cout << "Target polynomial function: " << endl;
        cout << res.getFunctionDefinition() << endl;
        CVector<CDouble> tx = df.getX();
        CVector<CDouble> ty = df.getY();
        GraphicManager::drawSingleXWithPoints(gnu_pipe, res.getFunctionDefinition(), tx.data, ty.data, df.getX().min(),
                                              df.getX().max());
    } else {
        cout << "To apply Gauss and Stirling method number of points must be odd" << endl;
    }

}
