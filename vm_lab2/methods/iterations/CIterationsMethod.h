//
// Created by artem on 24.02.2023.
//

#ifndef VM1_CITERATIONSMETHOD_H
#define VM1_CITERATIONSMETHOD_H

#define LIMIT_OF_ITERATIONS 50
#define DELTA 50

#include "./CIterationsResult.cpp"

class CIterationsMethod {
public:
    static enum MethodResult validateBorder(float f(float), float phi_derivative(float), float border_left, float border_right);
    static CIterationsResult performMethod(float f(float), float phi(float), float phi_derivative(float), float initial_border_left, float initial_border_right, float eps);
};


#endif //VM1_CITERATIONSMETHOD_H
