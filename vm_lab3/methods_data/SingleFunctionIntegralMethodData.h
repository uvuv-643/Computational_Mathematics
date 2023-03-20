//
// Created by artem on 27.02.2023.
//

#ifndef VM1_SINGLEFUNCTIONINTEGRALMETHODDATA_H
#define VM1_SINGLEFUNCTIONINTEGRALMETHODDATA_H

#include "../../functions/CFunctionSV.h"
#include "../methods/rectangular/RectMethodType.h"

class SingleFunctionIntegralMethodData {
    CFunctionSV *f;
    float a;
    float b;
    float eps;
public:
    SingleFunctionIntegralMethodData();

    SingleFunctionIntegralMethodData(CFunctionSV *f, float a, float b, float eps);

    SingleFunctionIntegralMethodData(CFunctionSV *f, float a, float b);

    CFunctionSV *getF();

    float getA() const;

    float getB() const;

    float getEps() const;

};


#endif //VM1_SINGLEFUNCTIONINTEGRALMETHODDATA_H
