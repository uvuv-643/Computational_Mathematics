//
// Created by artem on 23.02.2023.
//

#include "CFunctionManager.h"

float f1(float x) {
    return pow(x, 3) - x + 4;
}

float f1_der(float x) {
    return 3.0 * pow(x, 2) - 1;
}

float f1_sec_der(float x) {
    return 6 * x;
}

float f1_phi(float x) {
    return 12.0 / 11.0 * x - 1.0 / 11.0 * pow(x, 3) - 4.0 / 11.0;
}

float f1_phi_der(float x) {
    return 12.0 / 11.0 - 3.0 * 1.0 / 11.0 * pow(x, 2);
}

float g1(float x, float y) {
    return x * x + y * y - 4;
}

float g2(float x, float y) {
    return y - 3 * x * x;
}

float g1_derivative_x(float x, float y) {
    return 2 * x;
};

float g1_derivative_y(float x, float y) {
    return 2 * y;
};

float g2_derivative_x(float x, float y) {
    return - 6 * x;
};

float g2_derivative_y(float x, float y) {
    return 1;
};


CFunctionManager::CFunctionManager() {
    this->functions.push_back(new CFunctionSV("x^3 - x + 4", f1, f1_der, f1_sec_der, f1_phi, f1_phi_der));
    this->functions_multiple_variables.push_back(new CFunctionMV("x^2 + y^2 = 4", g1, g1_derivative_x, g1_derivative_y));
    this->functions_multiple_variables.push_back(new CFunctionMV("y = 3 * x^2" , g2, g2_derivative_x, g2_derivative_y));
}

vector<std::unique_ptr<CFunction>> CFunctionManager::operator[] (enum FunctionType type) {
    std::vector<std::unique_ptr<CFunction>> units;
    switch (type) {
        case SINGLE_VARIABLE: {
            for (auto & function : this->functions) {
                units.emplace_back(std::unique_ptr<CFunction>(function));
            }
            break;
        }
        case TWO_VARIABLES: {
            for (auto & function : this->functions_multiple_variables) {
                units.emplace_back(std::unique_ptr<CFunction>(function));
            }
            break;
        }
    }
    return units;
}
