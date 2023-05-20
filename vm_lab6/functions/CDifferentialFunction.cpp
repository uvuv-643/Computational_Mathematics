//
// Created by K49-R355-M11 on 20.05.2023.
//

#include "CDifferentialFunction.h"

CDifferentialFunction::CDifferentialFunction(string name, double f(double, double), double target(double)) {
    this->f = f;
    this->target = target;
    this->function_definition = name;
}