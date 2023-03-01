//
// Created by artem on 27.02.2023.
//

#ifndef VM1_MULTIPLEFUNCTIONMETHODDATA_H
#define VM1_MULTIPLEFUNCTIONMETHODDATA_H

#include "../../functions/CFunctionMV.h"

class MultipleFunctionMethodData {
    CFunctionMV* f;
    CFunctionMV* g;
    float a;
    float b;
    float eps;
public:
    MultipleFunctionMethodData();
    MultipleFunctionMethodData(CFunctionMV* f, CFunctionMV* g, float a, float b, float eps);
    CFunctionMV* getF();
    CFunctionMV* getG();
    float getA();
    float getB();
    float getEps();
};


#endif //VM1_MULTIPLEFUNCTIONMETHODDATA_H
