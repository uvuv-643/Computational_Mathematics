//
// Created by K49-R355-M11 on 20.05.2023.
//

#include "CDifferentialFunctionManager.h"

double f1(double x, double y) {
    return sqrt(y * y + 1) / (x * y);
}

double f2(double x, double y) {
    return (2 - y) * tan(x);
}

double f3(double x, double y) {
    return x * y * x * y * x * y * x * y * x;
}

double f4(double x, double y) {
    return sin(x);
}

double f1_target(double x) {
    return sqrt(pow(log(x), 2) - 1);
}

double f2_target(double x) {
    return 2 - cos(x);
}

double f3_target(double x) {
    return - pow(6, 1.0 / 3.0) / (pow(3, 1.0 / 3.0) * pow((pow(x, 6)), 1.0/3.0));
}

double f4_target(double x) {
    return -cos(x);
}


CDifferentialFunctionManager::CDifferentialFunctionManager() {
    this->functions.push_back(new CDifferentialFunction("sqrt(y * y + 1) / (x * y)", f1, f1_target));
    this->functions.push_back(new CDifferentialFunction("(2 - y) * tan(x)", f2, f2_target));
    this->functions.push_back(new CDifferentialFunction("x * y * x * y * x * y * x * y * x", f3, f3_target));
    this->functions.push_back(new CDifferentialFunction("sin(x)", f4, f4_target));
}

CDifferentialFunction* CDifferentialFunctionManager::get_function(int index) {
    return functions[index];
}