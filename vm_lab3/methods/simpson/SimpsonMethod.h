//
// Created by R1300-W-8-Stud on 16.03.2023.
//

#ifndef VM1_SIMPSONMETHOD_H
#define VM1_SIMPSONMETHOD_H

#define LIMIT_OF_ITERATIONS 10

#include "SimpsonMethodResult.cpp"
#include "../../methods_data/SingleFunctionMethodData.cpp"
#include <cstdint>

class SimpsonMethod {
public:
    static SimpsonMethodResult performIteration(CFunctionSV* f, float a, float b, size_t current_n);
    static SimpsonMethodResult perform(CFunctionSV* f,float a, float b, float eps, size_t initial_n);
};


#endif //VM1_SIMPSONMETHOD_H
