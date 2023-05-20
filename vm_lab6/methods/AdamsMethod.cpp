//
// Created by K49-R355-M11 on 20.05.2023.
//

#include "AdamsMethod.h"

AdamsMethod::AdamsMethod(double x_0, double x_n, double y_0, double h, double eps) {
    this->x_0 = x_0;
    this->x_n = x_n;
    this->y_0 = y_0;
    this->h = h;
    this->eps = eps;
}

vector<double> AdamsMethod::simple_iteration(CDifferentialFunction* function, double h) {
    size_t number_of_steps = (x_n - x_0) / h;
    vector<double> f_values(number_of_steps);
    for (size_t i = 0; i < 4; i++) {
        f_values[i] = function->f(x_0 + i * h, y_initial[i]);
    }
    for (size_t i = 3; i < number_of_steps - 1; i++) {
        double ff = f_values[i];
        double ff1 = f_values[i] - f_values[i - 1];
        double ff2 = f_values[i] - 2 * f_values[i - 1] + f_values[i - 2];
        double ff3 = f_values[i] - 3 * f_values[i - 1] + 3 * f_values[i - 2] - f_values[i - 3];
        double next_y = y_initial[i] + h * ff + h * h / 2 * ff1 + 5.0 / 12.0 * h * h * h * ff2 + 3.0 / 8.0 * h * h * h * h * ff3;
        f_values[i + 1] = function->f(x_0 + (i + 1) * h, next_y);
        y_initial.push_back(next_y);
    }
    return y_initial;

}

pair<double, vector<double>> AdamsMethod::perform_method(CDifferentialFunction* function) {
    vector<double> current_answer;
    size_t number_of_iteration;
    for (number_of_iteration = 0; number_of_iteration < LIMIT_OF_ITERATIONS; number_of_iteration++) {
        EulerModified method(x_0, x_n, y_0, h / pow(2, number_of_iteration), eps, 4);
        this->y_initial = method.perform_method(function).second;
        current_answer = simple_iteration(function, h / pow(2, number_of_iteration));
        double current_diff = 0;
        for (size_t i = 0; i < current_answer.size(); i++) {
            double x = x_0 + i * h;
            double target_value = function->target(x);
            double predicted_value = current_answer[i];
            current_diff = abs(predicted_value - target_value);
        }
        if (current_diff < eps) {
            break;
        }
    }
    vector<double> answer;
    for (size_t i = 0; i < current_answer.size(); i++) {
        if (i % (size_t) pow(2, min((size_t) LIMIT_OF_ITERATIONS - 1, number_of_iteration)) == 0) {
            answer.push_back(current_answer[i]);
        }
    }
    return {
        h / pow(2, number_of_iteration), answer
    };
}