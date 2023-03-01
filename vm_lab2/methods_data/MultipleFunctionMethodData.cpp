//
// Created by artem on 27.02.2023.
//

#include "MultipleFunctionMethodData.h"

float MultipleFunctionMethodData::getA() {
    return this->a;
};
float MultipleFunctionMethodData::getB() {
    return this->b;
};
float MultipleFunctionMethodData::getEps() {
    return this->eps;
};

CFunctionMV* MultipleFunctionMethodData::getF() {
    return this->f;
};

CFunctionMV* MultipleFunctionMethodData::getG() {
    return this->g;
};

MultipleFunctionMethodData::MultipleFunctionMethodData(CFunctionMV *f, CFunctionMV *g, float a, float b, float eps) {
    this->f = f;
    this->g = g;
    this->a = a;
    this->b = b;
    this->eps = eps;
}

MultipleFunctionMethodData::MultipleFunctionMethodData() {

}
