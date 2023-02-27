//
// Created by artem on 27.02.2023.
//

#ifndef VM1_SINGLEFUNCTIONMETHODDATA_H
#define VM1_SINGLEFUNCTIONMETHODDATA_H

#include "../../functions/CFunctionSV.h"

class SingleFunctionMethodData {
    CFunctionSV* f;
    float a;
    float b;
    float eps;
public:
    SingleFunctionMethodData(CFunctionSV* f, float a, float b, float eps);
    CFunctionSV* getF();
    float getA();
    float getB();
    float getEps();
};


#endif //VM1_SINGLEFUNCTIONMETHODDATA_H
