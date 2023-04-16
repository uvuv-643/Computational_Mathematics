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
    static enum MethodResult validateBorder(CFunctionSV* function_data, double border_left, double border_right);
    static CSecantResult performMethod(CFunctionSV* function_data, double initial_border_left, double initial_border_right, double eps);
};


#endif //VM1_CSECANTMETHOD_H
