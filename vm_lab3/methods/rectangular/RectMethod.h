//
// Created by R1300-W-8-Stud on 16.03.2023.
//

#ifndef VM1_RECTMETHOD_H
#define VM1_RECTMETHOD_H

#define LIMIT_OF_ITERATIONS 10

#include "RectMethodResult.cpp"
#include "./RectMethodType.h"
#include "../../methods_data/SingleFunctionMethodData.cpp"
#include <cstdint>

class RectMethod {
public:
    static RectMethodResult performIteration(CFunctionSV* f, enum RectMethodType type, float a, float b, size_t current_n);
    static RectMethodResult perform(CFunctionSV* f, enum RectMethodType type, float a, float b, float eps, size_t initial_n);
};


#endif //VM1_RECTMETHOD_H
