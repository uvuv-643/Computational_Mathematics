//
// Created by K49-R355-M11 on 20.05.2023.
//

#include "EulerMethod.h"

EulerMethod::EulerMethod(double x_0, double x_n, double y_0, double h, double eps, size_t limit) {
    this->x_0 = x_0;
    this->y_0 = y_0;
    this->x_n = x_n;
    this->h = h;
    this->eps = eps;
    this->limit = limit;
}

vector<double> EulerMethod::simple_iteration(CDifferentialFunction* function, double h, size_t number_of_iteration) {
    vector<double> current_answer;
    size_t number_of_steps = min(limit, (size_t) ((x_n - x_0) / h));
    double current_y = y_0;
    for (size_t i = 0; i < number_of_steps; i++) {
        if (i % (size_t) pow(2, min((size_t) LIMIT_OF_ITERATIONS - 1, number_of_iteration)) == 0) {
            current_answer.push_back(current_y);
        }
        current_y = current_y + h * function->f(x_0 + i * h, current_y);
    }
    return current_answer;
}

pair<double, vector<double>> EulerMethod::perform_method(CDifferentialFunction* function) {
    double diff = INF;
    size_t number_of_iteration = 1;
    vector<double> current_solution = this->simple_iteration(function, h, 0);
    while (number_of_iteration < LIMIT_OF_ITERATIONS && diff > eps) {
        double current_diff = 0;
        vector<double> next_solution = this->simple_iteration(function, h / pow(2, number_of_iteration), number_of_iteration);
        size_t actual_size = min(current_solution.size(), next_solution.size());
        for (size_t i = 0; i < actual_size; i++) {
            current_diff = max(current_diff, abs(current_solution[i] - next_solution[i])) / METHOD_K;
        }
        number_of_iteration += 1;
        diff = current_diff;
        current_solution = next_solution;
    }

    return {
        h / pow(2, number_of_iteration), current_solution
    };

}
