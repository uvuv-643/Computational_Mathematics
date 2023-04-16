//
// Created by artem on 27.02.2023.
//

#ifndef VM1_SINGLEFUNCTIONINTEGRALMETHODDATA_H
#define VM1_SINGLEFUNCTIONINTEGRALMETHODDATA_H

#include "../../functions/CFunctionSV.h"
#include "../methods/rectangular/RectMethodType.h"

class SingleFunctionIntegralMethodData {
    CFunctionSV *f;
    double a;
    double b;
    double eps;
public:
    SingleFunctionIntegralMethodData();

    SingleFunctionIntegralMethodData(CFunctionSV *f, double a, double b, double eps);

    SingleFunctionIntegralMethodData(CFunctionSV *f, double a, double b);

    CFunctionSV *getF();

    double getA() const;

    double getB() const;

    double getEps() const;

};


#endif //VM1_SINGLEFUNCTIONINTEGRALMETHODDATA_H
