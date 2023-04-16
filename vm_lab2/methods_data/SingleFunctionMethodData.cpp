//
// Created by artem on 27.02.2023.
//

#include "SingleFunctionMethodData.h"

double SingleFunctionMethodData::getA() {
    return this->a;
};
double SingleFunctionMethodData::getB() {
    return this->b;
};
double SingleFunctionMethodData::getEps() {
    return this->eps;
};

CFunctionSV* SingleFunctionMethodData::getF() {
    return this->f;
};

SingleFunctionMethodData::SingleFunctionMethodData(CFunctionSV *f, double a, double b, double eps) {
    this->f = f;
    this->a = a;
    this->b = b;
    this->eps = eps;
}

SingleFunctionMethodData::SingleFunctionMethodData() {

}

