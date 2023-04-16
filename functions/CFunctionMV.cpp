//
// Created by artem on 26.02.2023.
//

#include "CFunctionMV.h"

CFunctionMV::CFunctionMV(string name, double f(double, double), double f_derivative_x(double, double), double f_derivative_y(double, double)) {
    this->function_definition = std::move(name);
    this->f = f;
    this->f_derivative_x = f_derivative_x;
    this->f_derivative_y = f_derivative_y;
}