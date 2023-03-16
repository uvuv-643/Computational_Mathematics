//
// Created by artem on 27.02.2023.
//

#include "SingleFunctionMethodData.h"

float SingleFunctionMethodData::getA() {
    return this->a;
};
float SingleFunctionMethodData::getB() {
    return this->b;
};

CFunctionSV* SingleFunctionMethodData::getF() {
    return this->f;
};

SingleFunctionMethodData::SingleFunctionMethodData(CFunctionSV *f, float a, float b, float eps) {
    this->f = f;
    this->a = a;
    this->b = b;
    this->eps = eps;
}

SingleFunctionMethodData::SingleFunctionMethodData() {

}
