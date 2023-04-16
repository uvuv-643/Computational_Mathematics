//
// Created by artem on 15.04.2023.
//

#ifndef VM1_LAB4_H
#define VM1_LAB4_H

#define ENV_PATH "SOURCE_PATH"

#include <cstdio>
#include "cmath"
#include <conio.h>
#include <fstream>
#include <iostream>
#include "../discrete_functions/DiscreteFunction.h"
#include "PolynomialRegression.h"

class Lab4 {
    static FILE* gnu_pipe;
public:
    static void runFromFile();
    static void runFromKeyboard();
};


#endif //VM1_LAB4_H
