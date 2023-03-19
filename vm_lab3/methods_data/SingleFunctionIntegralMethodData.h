//
// Created by artem on 27.02.2023.
//

#ifndef VM1_SINGLEFUNCTIONINTEGRALMETHODDATA_H
#define VM1_SINGLEFUNCTIONINTEGRALMETHODDATA_H

#include "../../functions/CFunctionSV.h"

class SingleFunctionIntegralMethodData {
    CFunctionSV *f;
    float a;
    float b;
public:
    SingleFunctionIntegralMethodData();

    SingleFunctionIntegralMethodData(CFunctionSV *f, float a, float b);

    CFunctionSV *getF();

    float getA() const;

    float getB() const;

};


#endif //VM1_SINGLEFUNCTIONINTEGRALMETHODDATA_H
