//
// Created by artem on 15.04.2023.
//

#ifndef VM1_LAB4_H
#define VM1_LAB4_H

#define ENV_PATH_INPUT "SOURCE_PATH_INPUT"
#define ENV_PATH_OUTPUT "SOURCE_PATH_OUTPUT"

#include <cstdio>
#include "cmath"
#include <conio.h>
#include <fstream>
#include <iostream>
#include "../discrete_functions/DiscreteFunction.h"
#include "Regression/PolynomialRegression.h"
#include "Regression/PowerRegression.h"
#include "Regression/ExpRegression.h"
#include "Regression/LogRegression.h"
#include "../functions/fixed_functions/PolynomialFunction.h"
#include "../functions/fixed_functions/ExpFunction.h"
#include "../functions/fixed_functions/PowerFunction.h"
#include "../functions/fixed_functions/LogFunction.h"
#include "Metrics.h"
#include "../graphic/GraphicManager.h"

class Lab4 {

    static CTable regression1_table;
    static CTable regression2_table;
    static CTable regression3_table;
    static CTable regression4_table;
    static CTable regression5_table;
    static CTable regression6_table;
    static CVector<string> final_functions;

public:
    static CTable getRegressionResult(CVector<CDouble>& x, CVector<CDouble>& y_true, CVector<CDouble>& y_pred);
    static void runFromFile();
    static void runFromKeyboard();
    static CTable performRegression(DiscreteFunction& df);

    static FILE* gnu_pipe;
};


#endif //VM1_LAB4_H
