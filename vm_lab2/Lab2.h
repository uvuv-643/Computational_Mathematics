//
// Created by artem on 23.02.2023.
//

#ifndef VM1_LAB2_H
#define VM1_LAB2_H

#include "./methods/half_dividing/CHalfDividingResult.h"
#include "./methods/secant/CSecantResult.h"
#include "./methods/iterations//CIterationsResult.h"
#include "../functions/CFunctionSV.h"
#include "../functions/CFunctionMV.h"
#include "methods/newton/CNewtonResult.h"
#include "./methods_data/SingleFunctionMethodData.cpp"
#include "./methods_data/MultipleFunctionMethodData.cpp"
#include "../functions/CFunctionManager.cpp"
#include "../data_structures/CTable.cpp"
#include "./methods/half_dividing/CHalfDividingMethod.cpp"
#include "./methods/secant/CSecantMethod.cpp"
#include "./methods/iterations/CIterationsMethod.cpp"
#include "./methods/newton/CNewtonMethod.cpp"

class Lab2 {
public:
    static void runFromFile();
    static void runFromKeyboard();
    static void outputResult(CHalfDividingResult& result, CFunctionSV* function_data);
    static void outputResult(CSecantResult& result, CFunctionSV* function_data);
    static void outputResult(CIterationsResult& result, CFunctionSV* function_data);
    static void outputResult(CNewtonResult &result, CFunctionMV* f, CFunctionMV* g);
    static SingleFunctionMethodData inputDataSingleFunction(CFunctionManager manager);
    static MultipleFunctionMethodData inputDataMultipleFunction(CFunctionManager manager);
};


#endif //VM1_LAB2_H
