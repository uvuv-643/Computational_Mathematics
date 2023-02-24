//
// Created by artem on 24.02.2023.
//

#ifndef VM1_CFUNCTION_H
#define VM1_CFUNCTION_H

#include <functional>

using namespace std;

class CFunction {
public:

    float (*f)(float);
    float (*f_derivative)(float);
    float (*f_second_derivative)(float);
    float (*phi)(float);
    float (*phi_derivative)(float);

    CFunction(float f(float), float f_derivative(float), float f_second_derivative(float), float phi(float),
              float phi_derivative(float));

};


#endif //VM1_CFUNCTION_H
