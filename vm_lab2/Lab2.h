//
// Created by artem on 23.02.2023.
//

#ifndef VM1_LAB2_H
#define VM1_LAB2_H

#define ENV_PATH "SOURCE_PATH"

#include <algorithm>
#include <cmath>
#include <conio.h>
#include <fstream>

#include "./methods/half_dividing/CHalfDividingResult.h"
#include "./methods/secant/CSecantResult.h"
#include "./methods/iterations//CIterationsResult.h"
#include "../functions/CFunctionSV.h"
#include "../functions/CFunctionMV.h"
#include "methods/newton/CNewtonResult.h"
#include "./methods_data/SingleFunctionMethodData.h"
#include "./methods_data/MultipleFunctionMethodData.h"
#include "../functions/CFunctionManager.h"
#include "../data_structures/CTable.h"
#include "./methods/half_dividing/CHalfDividingMethod.h"
#include "./methods/secant/CSecantMethod.h"
#include "./methods/iterations/CIterationsMethod.h"
#include "./methods/newton/CNewtonMethod.h"
#include "../graphic/GraphicManager.h"

class Lab2 {
    static FILE* gnu_pipe;
public:
    static void runFromFile();
    static void runFromKeyboard();
    static SingleFunctionMethodData inputDataSingleFunction(CFunctionManager manager);
    static MultipleFunctionMethodData inputDataMultipleFunction(CFunctionManager manager);
};


#endif //VM1_LAB2_H
