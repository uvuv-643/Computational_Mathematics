//
// Created by artem on 24.02.2023.
//

#ifndef VM1_CSECANTMETHOD_H
#define VM1_CSECANTMETHOD_H

#define LIMIT_OF_ITERATIONS 50
#define DELTA 50

#include "./CSecantResult.h"

class CSecantMethod {
public:
    static enum MethodResult validateBorder(CFunctionSV* function_data, float border_left, float border_right);
    static CSecantResult performMethod(CFunctionSV* function_data, float initial_border_left, float initial_border_right, float eps);
};


#endif //VM1_CSECANTMETHOD_H
