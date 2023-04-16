//
// Created by artem on 26.02.2023.
//

#ifndef VM1_CFUNCTIONSV_H
#define VM1_CFUNCTIONSV_H

#include "./CFunction.h"

class CFunctionSV : public CFunction {
public:

    string function_definition_phi;
    double (*f)(double);
    double (*f_derivative)(double);
    double (*f_second_derivative)(double);
    double (*phi)(double);
    double (*phi_derivative)(double);

    CFunctionSV(string name, string phi_name, double f(double), double f_derivative(double), double f_second_derivative(double), double phi(double),
                double phi_derivative(double));

};


#endif //VM1_CFUNCTIONSV_H
