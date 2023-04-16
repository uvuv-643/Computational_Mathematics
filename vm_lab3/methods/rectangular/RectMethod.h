//
// Created by R1300-W-8-Stud on 16.03.2023.
//

#ifndef VM1_RECTMETHOD_H
#define VM1_RECTMETHOD_H

#ifndef LIMIT_OF_ITERATIONS
#define LIMIT_OF_ITERATIONS 10
#endif

#include <cstdint>

#include "RectMethodResult.h"
#include "./RectMethodType.h"

class RectMethod {
public:
    static RectMethodResult performIteration(CFunctionSV* f, enum RectMethodType type, double a, double b, size_t current_n);
    static RectMethodResult perform(CFunctionSV* f, enum RectMethodType type, double a, double b, double eps, size_t initial_n);
};


#endif //VM1_RECTMETHOD_H
