//
// Created by artem on 24.02.2023.
//

#include "CFunction.h"

CFunction::CFunction(float f(float), float f_derivative(float), float f_second_derivative(float), float phi(float), float phi_derivative(float)) {
    this->f = f;
    this->f_derivative = f_derivative;
    this->f_second_derivative = f_second_derivative;
    this->phi = phi;
    this->phi_derivative = phi_derivative;
}