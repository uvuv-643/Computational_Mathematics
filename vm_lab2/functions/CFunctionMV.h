//
// Created by artem on 26.02.2023.
//

#ifndef VM1_CFUNCTIONMV_H
#define VM1_CFUNCTIONMV_H

#include "./CFunction.h"

class CFunctionMV : public CFunction {
public:

    float (*f_derivative_x)(float);
    float (*f_derivative_y)(float);

    CFunctionMV(float f(float), float f_derivative_x(float), float f_derivative_y(float));

};


#endif //VM1_CFUNCTIONMV_H
