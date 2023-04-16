//
// Created by artem on 26.02.2023.
//

#ifndef VM1_CFUNCTIONMV_H
#define VM1_CFUNCTIONMV_H

#include "./CFunction.h"

class CFunctionMV : public CFunction {
public:

    double (*f)(double, double);
    double (*f_derivative_x)(double, double);
    double (*f_derivative_y)(double, double);

    CFunctionMV(string name, double f(double, double), double f_derivative_x(double, double), double f_derivative_y(double, double));

};


#endif //VM1_CFUNCTIONMV_H
