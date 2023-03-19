//
// Created by artem on 26.02.2023.
//

#ifndef VM1_CNEWTONMETHOD_H
#define VM1_CNEWTONMETHOD_H

#ifndef LIMIT_OF_ITERATIONS
#define LIMIT_OF_ITERATIONS 50
#endif
#define DELTA 50

#include "../../../functions/CFunctionMV.h"
#include "./CNewtonResult.h"

class CNewtonMethod {
public:
    static CNewtonResult performMethod(CFunctionMV* first_function, CFunctionMV* second_function, float initial_x, float initial_y, float eps);
};


#endif //VM1_CNEWTONMETHOD_H
