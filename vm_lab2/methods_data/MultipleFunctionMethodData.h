//
// Created by artem on 27.02.2023.
//

#ifndef VM1_MULTIPLEFUNCTIONMETHODDATA_H
#define VM1_MULTIPLEFUNCTIONMETHODDATA_H

#include "../../functions/CFunctionMV.h"

class MultipleFunctionMethodData {
    CFunctionMV* f;
    CFunctionMV* g;
    double a;
    double b;
    double eps;
public:
    MultipleFunctionMethodData();
    MultipleFunctionMethodData(CFunctionMV* f, CFunctionMV* g, double a, double b, double eps);
    CFunctionMV* getF();
    CFunctionMV* getG();
    double getA();
    double getB();
    double getEps();
};


#endif //VM1_MULTIPLEFUNCTIONMETHODDATA_H
