//
// Created by artem on 27.02.2023.
//

#include "SingleFunctionIntegralMethodData.h"

double SingleFunctionIntegralMethodData::getA() const {
    return this->a;
};
double SingleFunctionIntegralMethodData::getB() const {
    return this->b;
};

CFunctionSV* SingleFunctionIntegralMethodData::getF() {
    return this->f;
};

SingleFunctionIntegralMethodData::SingleFunctionIntegralMethodData(CFunctionSV *f, double a, double b) {
    this->f = f;
    this->a = a;
    this->b = b;
    this->eps = 1;
}

SingleFunctionIntegralMethodData::SingleFunctionIntegralMethodData(CFunctionSV *f, double a, double b, double eps) {
    this->f = f;
    this->a = a;
    this->b = b;
    this->eps = eps;
}

SingleFunctionIntegralMethodData::SingleFunctionIntegralMethodData() {

}

double SingleFunctionIntegralMethodData::getEps() const {
    return eps;
}
