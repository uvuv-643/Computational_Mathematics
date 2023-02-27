//
// Created by artem on 26.02.2023.
//

#include <utility>
#include "CFunctionMV.h"

CFunctionMV::CFunctionMV(string name, float f(float, float), float f_derivative_x(float, float), float f_derivative_y(float, float)) {
    this->function_definition = std::move(name);
    this->f = f;
    this->f_derivative_x = f_derivative_x;
    this->f_derivative_y = f_derivative_y;
}