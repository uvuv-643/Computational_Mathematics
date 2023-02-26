//
// Created by artem on 26.02.2023.
//

#ifndef VM1_CNEWTONRESULT_H
#define VM1_CNEWTONRESULT_H

#include <cstdint>
#include "../../../io/CInt.cpp"
#include "../../../io/CFloat.cpp"
#include "../../../io/CSize.cpp"
#include "../../../data_structures/CVector.cpp"
#include "../MethodResult.h"

class CNewtonResult {
    CSize count_of_iterations;
    enum MethodResult method_result;
    CVector<CFloat> x;
    CVector<CFloat> y;
    CVector<CFloat> dx;
    CVector<CFloat> dy;
public:

    explicit CNewtonResult();

    explicit CNewtonResult(enum MethodResult method_result);

    CSize getCountOfIterations();

    enum MethodResult getMethodResult();

    void setMethodResult(enum MethodResult method_result);

    CVector<CFloat> getX();

    CVector<CFloat> getY();

    CVector<CFloat> getDX();

    CVector<CFloat> getDY();

    void append(CFloat &x, CFloat& y, CFloat& dx, CFloat& dy);
};


#endif //VM1_CNEWTONRESULT_H
