//
// Created by artem on 26.02.2023.
//

#include "CFunctionSV.h"


CFunctionSV::CFunctionSV(string name, string phi_name, double f(double), double f_derivative(double), double f_second_derivative(double), double phi(double), double phi_derivative(double)) {
    this->f = f;
    this->function_definition = std::move(name);
    this->function_definition_phi = std::move(phi_name);
    this->f_derivative = f_derivative;
    this->f_second_derivative = f_second_derivative;
    this->phi = phi;
    this->phi_derivative = phi_derivative;
}