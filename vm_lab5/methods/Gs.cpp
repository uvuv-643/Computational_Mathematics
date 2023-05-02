//
// Created by artem on 01.05.2023.
//

#include "Gs.h"

static double factorial(size_t n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

GsMethodResult Gs::performMethod(DiscreteFunction &df, CDouble target_x) {

    CVector<CDouble> x = df.getX();
    CVector<CDouble> y = df.getY();
    size_t number_of_points = x.n;
    if (number_of_points % 2 == 1) {
        CTable finiteDifferences = getTableOfFiniteDifferences(df);
        vector<vector<double>> fd = finiteDifferences.getData();
        size_t n = number_of_points / 2;
        double h = x[1] - x[0];
        double answer = y[n];
        for (size_t i = 0; i < n; i++) {
            double current_product = 1;
            for (size_t j = 1; j < 2 * i + 2; j++) {
                current_product *= ((target_x - x[n]) / h) + ((int32_t)(j / 2) * pow(-1, j + 1));
            }
            current_product /= factorial(2 * i + 1);
            current_product *= fd[n - i][2 * i + 2];
            answer += current_product;
        }
        for (size_t i = 0; i < n; i++) {
            double current_product = 1;
            for (size_t j = 1; j < 2 * i + 3; j++) {
                current_product *= ((target_x - x[n]) / h) + ((int32_t)(j / 2) * pow(-1, j + 1));
            }
            current_product /= factorial(2 * i + 2);
            current_product *= fd[n - i - 1][2 * i + 3];
            answer += current_product;
        }
        string function_definition = getFunctionDefinition(x, y, fd);
        return {true, function_definition, answer, std::move(finiteDifferences)};
    }
    return GsMethodResult(false);
}

CTable Gs::getTableOfFiniteDifferences(DiscreteFunction &df) {

    CVector<CDouble> x = df.getX();
    CVector<CDouble> y = df.getY();

    size_t number_of_points = df.getNumberOfPoints();
    CTable answer(number_of_points, true);
    answer.insert("x_i", x);
    answer.insert("y_i", y);

    vector<vector<CDouble>> dt(number_of_points, vector<CDouble>(number_of_points));
    for (size_t i = 0; i < number_of_points; i++) {
        dt[0][i] = y[i];
    }
    for (size_t i = 1; i < number_of_points; i++) {
        for (size_t j = 0; j < number_of_points - i; j++) {
            dt[i][j] = -dt[i - 1][j] + (double)dt[i - 1][j + 1];
        }
    }

    for (size_t i = 1; i < number_of_points; i++) {
        answer.insert("d" + to_string(i) + "y_i", dt[i]);
    }

    return answer;

}

string Gs::getFunctionDefinition(CVector<CDouble>& x, CVector<CDouble>& y, vector<vector<double>>& fd) {

    size_t n = (size_t) x.n / 2;
    string function_definition;
    vector<string> ts;
    for (size_t i = 0; i < n + 2; i++) {
        string t = "(x - " + to_string(x[n]) + ") / " + to_string(x[1] - x[0]);
        ts.push_back("(" + t + " - " + to_string(i) + ")");
        ts.push_back("(" + t + " + " + to_string(i) + ")");
    }
    if (x.data.size() % 2 == 1) {
        string t;
        function_definition += to_string(y[n]);
        for (size_t i = 0; i < n; i++) {
            t = "+";
            for (size_t j = 1; j < 2 * i + 2; j++) {
                t += ts[j] + "*";
            }
            t += to_string(fd[n - i][2 * i + 2]) + "/" + to_string(factorial(2 * i + 1));
            function_definition += t;

            t = "+";
            for (size_t j = 1; j < 2 * i + 3; j++) {
                t += ts[j] + "*";
            }
            t += to_string(fd[n - i - 1][2 * i + 3]) + "/" + to_string(factorial(2 * i + 2));
            function_definition += t;
        }
    }

    return function_definition;

}
