//
// Created by artem on 26.02.2023.
//

#include "CFunctionMV.h"

CFunctionMV::CFunctionMV(float f(float), float f_derivative_x(float), float f_derivative_y(float)) {
    this->f = f;
    this->f_derivative_x = f_derivative_x;
    this->f_derivative_y = f_derivative_y;
}