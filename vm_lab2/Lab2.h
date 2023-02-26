//
// Created by artem on 23.02.2023.
//

#ifndef VM1_LAB2_H
#define VM1_LAB2_H

#include "./methods/half_dividing/CHalfDividingResult.h"
#include "./methods/secant/CSecantResult.h"
#include "./methods/iterations//CIterationsResult.h"
#include "functions/CFunction.h"

class Lab2 {
public:
    static void runFromFile();
    static void runFromKeyboard();
    static void outputResult(CHalfDividingResult& result, CFunction* function_data);
    static void outputResult(CSecantResult& result, CFunction* function_data);
    static void outputResult(CIterationsResult& result, CFunction* function_data);
};


#endif //VM1_LAB2_H
