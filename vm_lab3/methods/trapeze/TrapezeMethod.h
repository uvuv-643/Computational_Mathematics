//
// Created by R1300-W-8-Stud on 16.03.2023.
//

#ifndef VM1_TRAPEZEMETHOD_H
#define VM1_TRAPEZEMETHOD_H

#ifndef LIMIT_OF_ITERATIONS
#define LIMIT_OF_ITERATIONS 10
#endif

#include <cstdint>
#include "TrapezeMethodResult.h"

class TrapezeMethod {
public:
    static TrapezeMethodResult performIteration(CFunctionSV* f, double a, double b, size_t current_n);
    static TrapezeMethodResult perform(CFunctionSV* f,double a, double b, double eps, size_t initial_n);
};


#endif //VM1_TRAPEZEMETHOD_H
