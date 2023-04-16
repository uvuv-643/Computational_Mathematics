//
// Created by artem on 23.02.2023.
//

#include "CFunctionManager.h"

#include <iostream>

using namespace std;

double f1(double x) {
    return pow(x, 3) - x + 4;
}

double f1_der(double x) {
    return 3.0 * pow(x, 2) - 1;
}

double f1_sec_der(double x) {
    return 6 * x;
}

double f1_phi(double x) {
    return 12.0 / 11.0 * x - 1.0 / 11.0 * pow(x, 3) - 4.0 / 11.0;
}

double f1_phi_der(double x) {
    return 12.0 / 11.0 - 3.0 * 1.0 / 11.0 * pow(x, 2);
}

double f2(double x) {
    return pow(x, 2) * exp(- pow(x, 2)) - 0.2;
}

double f2_der(double x) {
    return -2 * pow(x, 3) * exp(- pow(x, 2)) + 2 * x * exp(- pow(x, 2));
}

double f2_sec_der(double x) {
    return 2 * (1 - 5 * pow(x, 2) + 2 * pow(x, 4)) * exp(-pow(x, 2));
}

double f2_phi(double x) {
    return x - (f2(x));
}

double f2_phi_der(double x) {
    return 1 - (f2_der(x));
}

double f3(double x) {
    return sin(x) / M_PI;
}

double f3_der(double x) {
    return cos(x) / M_PI;
}

double f3_sec_der(double x) {
    return -sin(x) / M_PI;
}

double f3_phi(double x) {
    return x - sin(x) / M_PI;
}

double f3_phi_der(double x) {
    return 1 - cos(x) / M_PI;
}

double f4(double x) {
    return pow(x, 3) + 2.28 * pow(x, 2) - 1.934 * x - 3.907;
}

double f4_der(double x) {
    return 3 * pow(x, 2) - 6;
}

double f4_sec_der(double x) {
    return 6 * x;
}

double f4_phi(double x) {
    return x + 0.5 * (f4(x));
}

double f4_phi_der(double x) {
    return 1 + 0.5 * (f4_der(x));
}



double g1(double x, double y) {
    return x * x + y * y - 4;
}

double g2(double x, double y) {
    return y - 3 * x * x;
}

double g3(double x, double y) {
    return x * x - y * y - 1;
}
double g4(double x, double y) {
    return x * x * x - y + 1.5;
}

double g1_derivative_x(double x, double y) {
    return 2 * x;
};

double g1_derivative_y(double x, double y) {
    return 2 * y;
};

double g2_derivative_x(double x, double y) {
    return -6 * x;
};

double g2_derivative_y(double x, double y) {
    return 1;
};

double g3_derivative_x(double x, double y) {
    return 2 * x;
};

double g3_derivative_y(double x, double y) {
    return -2 * y;
};

double g4_derivative_x(double x, double y) {
    return 3 * x * x - 1;
};

double g4_derivative_y(double x, double y) {
    return -1;
};




CFunctionManager::CFunctionManager() {
    this->functions.push_back(new CFunctionSV("x^3 - x + 4", "12.0 / 11.0 * x - 1.0 / 11.0 * x**3 - 4.0 / 11.0", f1, f1_der, f1_sec_der, f1_phi, f1_phi_der));
    this->functions.push_back(new CFunctionSV("x^2 * exp(-x^2) - 0.2", "x - (x^2 * exp(-x^2) - 0.2)", f2, f2_der, f2_sec_der, f2_phi, f2_phi_der));
    this->functions.push_back(new CFunctionSV("sin(x) / pi", "x - sin(x) / pi", f3, f3_der, f3_sec_der, f3_phi, f3_phi_der));
    this->functions.push_back(new CFunctionSV("x^3 + 2.28 * x^2 - 1.934 * x - 3.907", "x - 0.1 * (x^3 + 2.28 * x^2 - 1.934 * x - 3.907)", f4, f4_der, f4_sec_der, f4_phi, f4_phi_der));
    this->functions_multiple_variables.push_back(new CFunctionMV("x^2 + y^2 - 4", g1, g1_derivative_x, g1_derivative_y));
    this->functions_multiple_variables.push_back(new CFunctionMV("y - 3 * x^2", g2, g2_derivative_x, g2_derivative_y));
    this->functions_multiple_variables.push_back(new CFunctionMV("x^2 - y^2 - 1", g3, g3_derivative_x, g3_derivative_y));
    this->functions_multiple_variables.push_back(new CFunctionMV("x^3 - y + 1.5", g4, g4_derivative_x, g4_derivative_y));
}

vector<CFunctionSV*> CFunctionManager::getSingleFunctions() {
    return this->functions;
}
vector<CFunctionMV*> CFunctionManager::getMultipleFunctions() {
    return this->functions_multiple_variables;
}

