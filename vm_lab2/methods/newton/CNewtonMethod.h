//
// Created by artem on 26.02.2023.
//

#ifndef VM1_CNEWTONMETHOD_H
#define VM1_CNEWTONMETHOD_H

#define LIMIT_OF_ITERATIONS 50
#define DELTA 50

#include "../../functions/CFunction.h"
#include "./CNewtonResult.cpp"

class CNewtonMethod {
public:
    static enum MethodResult validateBorder(CFunction* function_data, float border_left, float border_right);
    static CNewtonResult performMethod(vector<CFunction*> function_data, float initial_border_left, float initial_border_right, float eps);
};


#endif //VM1_CNEWTONMETHOD_H
