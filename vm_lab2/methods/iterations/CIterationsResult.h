//
// Created by artem on 24.02.2023.
//

#ifndef VM1_CITERATIONSRESULT_H
#define VM1_CITERATIONSRESULT_H

#include <cstdint>
#include "../../../io/CInt.cpp"
#include "../../../io/CFloat.cpp"
#include "../../../io/CSize.cpp"
#include "../../../data_structures/CVector.cpp"
#include "../MethodResult.h"

class CIterationsResult {
    CSize count_of_iterations;
    enum MethodResult method_result;
    CVector<CFloat> x;
    CVector<CFloat> y;
public:

    explicit CIterationsResult();

    explicit CIterationsResult(enum MethodResult method_result);

    CSize getCountOfIterations();

    enum MethodResult getMethodResult();

    void setMethodResult(enum MethodResult method_result);

    CVector<CFloat> getX();

    CVector<CFloat> getY();

    void append(CFloat &x, CFloat &y);

};


#endif //VM1_CITERATIONSRESULT_H
