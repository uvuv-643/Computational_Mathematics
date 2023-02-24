//
// Created by artem on 23.02.2023.
//

#ifndef VM1_LAB2_H
#define VM1_LAB2_H

#include "./methods/half_dividing/CHalfDividingResult.h"
#include "./methods/secant/CSecantResult.h"

class Lab2 {
public:
    static void runFromFile();
    static void runFromKeyboard();
    static void outputResult(CHalfDividingResult& result, float f(float));
    static void outputResult(CSecantResult& result, float f(float));
};


#endif //VM1_LAB2_H
