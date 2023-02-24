//
// Created by artem on 23.02.2023.
//

#ifndef VM1_CHALFDIVIDINGMETHOD_H
#define VM1_CHALFDIVIDINGMETHOD_H

#define LIMIT_OF_ITERATIONS 50
#define DELTA 50

#include "./CHalfDividingResult.cpp"

using namespace std;

class CHalfDividingMethod {
public:
    static enum MethodResult validateBorder(float f(float), float derivative(float), float border_left, float border_right);
    static CHalfDividingResult performMethod(float f(float), float derivative(float), float initial_border_left, float initial_border_right, float eps);
};


#endif //VM1_CLFDIVIDINGMETHOD_H