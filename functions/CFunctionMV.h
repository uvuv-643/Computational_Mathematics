//
// Created by artem on 26.02.2023.
//

#ifndef VM1_CFUNCTIONMV_H
#define VM1_CFUNCTIONMV_H

#include "./CFunction.h"

class CFunctionMV : public CFunction {
public:

    float (*f)(float, float);
    float (*f_derivative_x)(float, float);
    float (*f_derivative_y)(float, float);

    CFunctionMV(string name, float f(float, float), float f_derivative_x(float, float), float f_derivative_y(float, float));

};


#endif //VM1_CFUNCTIONMV_H
