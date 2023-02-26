//
// Created by artem on 26.02.2023.
//

#ifndef VM1_CFUNCTIONSW_H
#define VM1_CFUNCTIONSW_H

#include "./CFunction.h"


class CFunctionSW : public CFunction {
public:

    float (*f_derivative)(float);
    float (*f_second_derivative)(float);
    float (*phi)(float);
    float (*phi_derivative)(float);

    CFunctionSW(float f(float), float f_derivative(float), float f_second_derivative(float), float phi(float),
              float phi_derivative(float));

};


#endif //VM1_CFUNCTIONSW_H
