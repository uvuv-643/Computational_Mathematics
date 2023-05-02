//
// Created by artem on 15.04.2023.
//

#include "Lab4.h"

CTable Lab4::regression1_table;
CTable Lab4::regression2_table;
CTable Lab4::regression3_table;
CTable Lab4::regression4_table;
CTable Lab4::regression5_table;
CTable Lab4::regression6_table;
CVector<string> Lab4::final_functions;
FILE* Lab4::gnu_pipe;

void Lab4::runFromFile() {

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

    ofstream fs1;

    DiscreteFunction df("lab4");
    fs >> df;

    cout << endl << "Inputted data" << endl;
    cout << df << endl;

    string file; fs >> file;

    ostream *os = &cout;
    if (file == "file") {
        string file_path_out = std::getenv(ENV_PATH_OUTPUT);
        if (file_path_out.empty()) {
            cerr << "Not found env. variable '" << ENV_PATH_OUTPUT << "'" << endl;
        } else {
            fs1.open(std::getenv(ENV_PATH_OUTPUT));
            if (fs1.fail()) {
                cerr << "File not found. Make sure that it exists" << endl;
            } else {
                os = &fs1;
            }
        }
    }

    Lab4::gnu_pipe = _popen("gnuplot -persist", "w");

    CTable answers = Lab4::performRegression(df);

    CVector<CDouble> tx = df.getX();
    CVector<CDouble> ty = df.getY();

    (*os) << "Corr coefficient" << endl;
    (*os) << Metrics::corr(tx, ty) << endl << endl;

    (*os) << "Linear function approximation" << endl;
    (*os) << regression1_table << endl;
    (*os) << "Squared function approximation" << endl;
    (*os) << regression2_table << endl;
    (*os) << "Cubed function approximation" << endl;
    (*os) << regression3_table << endl;

    if (regression4_table.isFilled()) {
        (*os) << "Power function approximation" << endl;
        (*os) << regression4_table << endl;
    } else {
        (*os) << "Unable to create power function approximation. There is negative x or y point" << endl << endl;
    }

    if (regression5_table.isFilled()) {
        (*os) << "Exp function approximation" << endl;
        (*os) << regression5_table << endl;
    } else {
        (*os) << "Unable to create exp function approximation. There is negative y point" << endl << endl;
    }

    if (regression6_table.isFilled()) {
        (*os) << "Log function approximation" << endl;
        (*os) << regression6_table << endl;
    } else {
        (*os) << "Unable to create log function approximation. There is negative x point" << endl << endl;
    }

    (*os) << "Final answer" << endl;
    (*os) << answers << endl;

    std::ostringstream oss;
    if (!Lab4::final_functions.empty()) {
        oss << Lab4::final_functions[0];
        for (int i = 1; i < (size_t) Lab4::final_functions.n; i++) {
            oss << ", " << Lab4::final_functions[i];
        }
    }

    GraphicManager::drawSingleXWithPoints(gnu_pipe, oss.str(), tx.data, ty.data, df.getX().min(), df.getX().max());

}

void Lab4::runFromKeyboard() {

    ofstream fs;

    DiscreteFunction df("lab4");
    cin >> df;

    cout << endl << "Inputted data" << endl;
    cout << df << endl;

    cout << "Type 'file' if you want to save result in file from ENV" << endl;
    string file; cin >> file;

    ostream *os = &cout;
    if (file == "file") {
        string file_path = std::getenv(ENV_PATH_OUTPUT);
        if (file_path.empty()) {
            cerr << "Not found env. variable '" << ENV_PATH_OUTPUT << "'" << endl;
        } else {
            fs.open(std::getenv(ENV_PATH_OUTPUT));
            if (fs.fail()) {
                cerr << "File not found. Make sure that it exists" << endl;
            } else {
                os = &fs;
            }
        }
    }

    Lab4::gnu_pipe = _popen("gnuplot -persist", "w");


    CVector<CDouble> tx = df.getX();
    CVector<CDouble> ty = df.getY();

    (*os) << "Corr coefficient" << endl;
    (*os) << Metrics::corr(tx, ty) << endl << endl;

    CTable answers = Lab4::performRegression(df);

    (*os) << "Linear function approximation" << endl;
    (*os) << regression1_table << endl;
    (*os) << "Squared function approximation" << endl;
    (*os) << regression2_table << endl;
    (*os) << "Cubed function approximation" << endl;
    (*os) << regression3_table << endl;

    if (regression4_table.isFilled()) {
        (*os) << "Power function approximation" << endl;
        (*os) << regression4_table << endl;
    } else {
        (*os) << "Unable to create power function approximation. There is negative x or y point" << endl << endl;
    }

    if (regression5_table.isFilled()) {
        (*os) << "Exp function approximation" << endl;
        (*os) << regression5_table << endl;
    } else {
        (*os) << "Unable to create exp function approximation. There is negative y point" << endl << endl;
    }

    if (regression6_table.isFilled()) {
        (*os) << "Log function approximation" << endl;
        (*os) << regression6_table << endl;
    } else {
        (*os) << "Unable to create log function approximation. There is negative x point" << endl << endl;
    }

    (*os) << "Final answer" << endl;
    (*os) << answers << endl;

    std::ostringstream oss;
    if (!Lab4::final_functions.empty()) {
        oss << Lab4::final_functions[0];
        for (int i = 1; i < (size_t) Lab4::final_functions.n; i++) {
            oss << ", " << Lab4::final_functions[i];
        }
    }

    GraphicManager::drawSingleXWithPoints(gnu_pipe, oss.str(), tx.data, ty.data, df.getX().min(), df.getX().max());

}

CTable Lab4::getRegressionResult(CVector<CDouble> &x, CVector<CDouble> &y_true, CVector<CDouble> &y_pred) {
    CTable regression_table = CTable(y_pred.n, true);
    regression_table.insert("x", x);
    regression_table.insert("y_true", y_true);
    regression_table.insert("y_pred", y_pred);
    regression_table.insert("error", (y_true - y_pred).apply([](double t) { return pow(t, 2); }));
    return regression_table;
}

CTable Lab4::performRegression(DiscreteFunction& df) {

    CVector<CDouble> tx = df.getX();
    CVector<CDouble> ty = df.getY();
    bool is_positive_x = true;
    bool is_positive_y = true;
    for (size_t i = 0; i < df.getNumberOfPoints(); i++) {
        if (tx[i] <= 0) is_positive_x = false;
        if (ty[i] <= 0) is_positive_y = false;
    }

    size_t number_of_rows = 6;
    if (!is_positive_x || !is_positive_y) {
        number_of_rows = 4;
    }
    if (!is_positive_x && !is_positive_y) {
        number_of_rows = 3;
    }

    CTable answers = CTable(number_of_rows, true);

    CVector<string> functions;
    CVector<CDouble> mses;
    CVector<CDouble> sds;
    CVector<CDouble> r2_scores;

    CVector<CDouble> y_pred;

    PolynomialRegression regression1 = PolynomialRegression(1);
    CVector<CDouble> answer1 = regression1.performMethod(df.getNumberOfPoints(), tx, ty);
    PolynomialFunction answer1_function(1, answer1);
    functions.push_back(PolynomialRegression::createDefinition(answer1));
    y_pred = answer1_function.apply(tx);
    mses.push_back(Metrics::mse(ty, y_pred));
    sds.push_back(Metrics::sd(ty, y_pred));
    r2_scores.push_back(Metrics::r2_score(ty, y_pred));
    regression1_table = Lab4::getRegressionResult(tx, ty, y_pred);

    PolynomialRegression regression2 = PolynomialRegression(2);
    CVector<CDouble> answer2 = regression2.performMethod(df.getNumberOfPoints(), tx, ty);
    PolynomialFunction answer2_function(2, answer2);
    functions.push_back(PolynomialRegression::createDefinition(answer2));
    y_pred = answer2_function.apply(tx);
    mses.push_back(Metrics::mse(ty, y_pred));
    sds.push_back(Metrics::sd(ty, y_pred));
    r2_scores.push_back(Metrics::r2_score(ty, y_pred));
    regression2_table = Lab4::getRegressionResult(tx, ty, y_pred);

    PolynomialRegression regression3 = PolynomialRegression(3);
    CVector<CDouble> answer3 = regression3.performMethod(df.getNumberOfPoints(), tx, ty);
    PolynomialFunction answer3_function(3, answer3);
    functions.push_back(PolynomialRegression::createDefinition(answer3));
    y_pred = answer3_function.apply(tx);
    mses.push_back(Metrics::mse(ty, y_pred));
    sds.push_back(Metrics::sd(ty, y_pred));
    r2_scores.push_back(Metrics::r2_score(ty, y_pred));
    regression3_table = Lab4::getRegressionResult(tx, ty, y_pred);

    if (is_positive_x && is_positive_y) {
        PowerRegression regression4 = PowerRegression();
        CVector<CDouble> answer4 = regression4.performMethod(df.getNumberOfPoints(), tx, ty);
        PowerFunction answer4_function(answer4);
        functions.push_back(PowerRegression::createDefinition(answer4));
        y_pred = answer4_function.apply(tx);
        mses.push_back(Metrics::mse(ty, y_pred));
        sds.push_back(Metrics::sd(ty, y_pred));
        r2_scores.push_back(Metrics::r2_score(ty, y_pred));
        regression4_table = Lab4::getRegressionResult(tx, ty, y_pred);
    }

    if (is_positive_y) {
        ExpRegression regression5 = ExpRegression();
        CVector<CDouble> answer5 = regression5.performMethod(df.getNumberOfPoints(), tx, ty);
        ExpFunction answer5_function(answer5);
        functions.push_back(ExpRegression::createDefinition(answer5));
        y_pred = answer5_function.apply(tx);
        mses.push_back(Metrics::mse(ty, y_pred));
        sds.push_back(Metrics::sd(ty, y_pred));
        r2_scores.push_back(Metrics::r2_score(ty, y_pred));
        regression5_table = Lab4::getRegressionResult(tx, ty, y_pred);
    }

    if (is_positive_x) {
        LogRegression regression6 = LogRegression();
        CVector<CDouble> answer6 = regression6.performMethod(df.getNumberOfPoints(), tx, ty);
        LogFunction answer6_function(answer6);
        functions.push_back(LogRegression::createDefinition(answer6));
        y_pred = answer6_function.apply(tx);
        mses.push_back(Metrics::mse(ty, y_pred));
        sds.push_back(Metrics::sd(ty, y_pred));
        r2_scores.push_back(Metrics::r2_score(ty, y_pred));
        regression6_table = Lab4::getRegressionResult(tx, ty, y_pred);
    }

    Lab4::final_functions = functions;

    answers.insert("Function", functions);
    answers.insert("MSE", mses);
    answers.insert("SD", sds);
    answers.insert("R2 score", r2_scores);

    return answers;

}
