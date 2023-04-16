//
// Created by artem on 27.02.2023.
//

#include "MultipleFunctionMethodData.h"

double MultipleFunctionMethodData::getA() {
    return this->a;
};
double MultipleFunctionMethodData::getB() {
    return this->b;
};
double MultipleFunctionMethodData::getEps() {
    return this->eps;
};

CFunctionMV* MultipleFunctionMethodData::getF() {
    return this->f;
};

CFunctionMV* MultipleFunctionMethodData::getG() {
    return this->g;
};

MultipleFunctionMethodData::MultipleFunctionMethodData(CFunctionMV *f, CFunctionMV *g, double a, double b, double eps) {
    this->f = f;
    this->g = g;
    this->a = a;
    this->b = b;
    this->eps = eps;
}

MultipleFunctionMethodData::MultipleFunctionMethodData() {

}
