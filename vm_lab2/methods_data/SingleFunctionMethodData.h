//
// Created by artem on 27.02.2023.
//

#ifndef VM1_SINGLEFUNCTIONMETHODDATA_H
#define VM1_SINGLEFUNCTIONMETHODDATA_H

#include "../../functions/CFunctionSV.h"

class SingleFunctionMethodData {
    CFunctionSV* f;
    double a;
    double b;
    double eps;
public:
    SingleFunctionMethodData();
    SingleFunctionMethodData(CFunctionSV* f, double a, double b, double eps);
    CFunctionSV* getF();
    double getA();
    double getB();
    double getEps();
};


#endif //VM1_SINGLEFUNCTIONMETHODDATA_H
