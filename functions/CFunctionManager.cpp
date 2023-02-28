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

float f2(float x) {
    return pow(x, 2) * exp(- pow(x, 2)) - 0.2;
}

float f2_der(float x) {
    return -2 * pow(x, 3) * exp(- pow(x, 2)) + 2 * x * exp(- pow(x, 2));
}

float f2_sec_der(float x) {
    return 2 * (1 - 5 * pow(x, 2) + 2 * pow(x, 4)) * exp(-pow(x, 2));
}

float f2_phi(float x) {
    return x - (f2(x));
}

float f2_phi_der(float x) {
    return 1 - (f2_der(x));
}

float f3(float x) {
    return sin(x) / M_PI;
}

float f3_der(float x) {
    return cos(x) / M_PI;
}

float f3_sec_der(float x) {
    return -sin(x) / M_PI;
}

float f3_phi(float x) {
    return x - sin(x) / M_PI;
}

float f3_phi_der(float x) {
    return 1 - cos(x) / M_PI;
}

float f4(float x) {
    return pow(x, 3) + 2.28 * pow(x, 2) - 1.934 * x - 3.907;
}

float f4_der(float x) {
    return 3 * pow(x, 2) + 2 * 2.28 * pow(x, 1) - 1.934;
}

float f4_sec_der(float x) {
    return 6 * pow(x, 1) + 2 * 2.28;
}

float f4_phi(float x) {
    return x - 0.1 * (f4(x));
}

float f4_phi_der(float x) {
    return 1 - 0.1 * (f4_der(x));
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
    return -6 * x;
};

float g2_derivative_y(float x, float y) {
    return 1;
};


CFunctionManager::CFunctionManager() {
    this->functions.push_back(new CFunctionSV("x^3 - x + 4", "12.0 / 11.0 * x - 1.0 / 11.0 * x**3 - 4.0 / 11.0", f1, f1_der, f1_sec_der, f1_phi, f1_phi_der));
    this->functions.push_back(new CFunctionSV("x^2 * exp(-x^2) - 0.2", "x - (x^2 * exp(-x^2) - 0.2)", f2, f2_der, f2_sec_der, f2_phi, f2_phi_der));
    this->functions.push_back(new CFunctionSV("sin(x) / pi", "x - sin(x) / pi", f3, f3_der, f3_sec_der, f3_phi, f3_phi_der));
    this->functions.push_back(new CFunctionSV("x^3 + 2.28 * x^2 - 1.934 * x - 3.907", "x - 0.1 * (x^3 + 2.28 * x^2 - 1.934 * x - 3.907)", f4, f4_der, f4_sec_der, f4_phi, f4_phi_der));
    this->functions_multiple_variables.push_back(new CFunctionMV("x^2 + y^2 - 4", g1, g1_derivative_x, g1_derivative_y));
    this->functions_multiple_variables.push_back(new CFunctionMV("y - 3 * x^2", g2, g2_derivative_x, g2_derivative_y));
}

vector<std::unique_ptr<CFunction>> CFunctionManager::operator[](enum FunctionType type) {
    std::vector<std::unique_ptr<CFunction>> units;
    switch (type) {
        case SINGLE_VARIABLE: {
            for (auto &function: this->functions) {
                units.emplace_back(std::unique_ptr<CFunction>(function));
            }
            break;
        }
        case TWO_VARIABLES: {
            for (auto &function: this->functions_multiple_variables) {
                units.emplace_back(std::unique_ptr<CFunction>(function));
            }
            break;
        }
    }
    return units;
}
