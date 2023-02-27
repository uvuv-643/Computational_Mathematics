//
// Created by artem on 26.02.2023.
//

#ifndef VM1_CFUNCTIONSV_H
#define VM1_CFUNCTIONSV_H

#include "./CFunction.h"


class CFunctionSV : public CFunction {
public:

    float (*f)(float);
    float (*f_derivative)(float);
    float (*f_second_derivative)(float);
    float (*phi)(float);
    float (*phi_derivative)(float);

    CFunctionSV(string name, float f(float), float f_derivative(float), float f_second_derivative(float), float phi(float),
                float phi_derivative(float));

};


#endif //VM1_CFUNCTIONSV_H
