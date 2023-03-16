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
public:
    SingleFunctionMethodData();
    SingleFunctionMethodData(CFunctionSV* f, float a, float b);
    CFunctionSV* getF();
    float getA();
    float getB();
};


#endif //VM1_SINGLEFUNCTIONMETHODDATA_H
