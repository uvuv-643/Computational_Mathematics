//
// Created by artem on 27.02.2023.
//

#include "SingleFunctionIntegralMethodData.h"

float SingleFunctionIntegralMethodData::getA() const {
    return this->a;
};
float SingleFunctionIntegralMethodData::getB() const {
    return this->b;
};

CFunctionSV* SingleFunctionIntegralMethodData::getF() {
    return this->f;
};

SingleFunctionIntegralMethodData::SingleFunctionIntegralMethodData(CFunctionSV *f, float a, float b) {
    this->f = f;
    this->a = a;
    this->b = b;
    this->eps = 1;
}

SingleFunctionIntegralMethodData::SingleFunctionIntegralMethodData(CFunctionSV *f, float a, float b, float eps) {
    this->f = f;
    this->a = a;
    this->b = b;
    this->eps = eps;
}

SingleFunctionIntegralMethodData::SingleFunctionIntegralMethodData() {

}

float SingleFunctionIntegralMethodData::getEps() const {
    return eps;
}
