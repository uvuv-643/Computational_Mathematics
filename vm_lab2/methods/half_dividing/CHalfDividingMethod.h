//
// Created by artem on 23.02.2023.
//

#ifndef VM1_CHALFDIVIDINGMETHOD_H
#define VM1_CHALFDIVIDINGMETHOD_H

#define LIMIT_OF_ITERATIONS 50
#define DELTA 50

#include "./CHalfDividingResult.h"
#include "../../../functions/CFunctionSV.h"

using namespace std;

class CHalfDividingMethod {
public:
    static enum MethodResult validateBorder(CFunctionSV* function_data, double border_left, double border_right);
    static CHalfDividingResult performMethod(CFunctionSV* function_data, double initial_border_left, double initial_border_right, double eps);
};


#endif //VM1_CLFDIVIDINGMETHOD_H
