//
// Created by artem on 24.02.2023.
//

#ifndef VM1_CSECANTRESULT_H
#define VM1_CSECANTRESULT_H

#include <cstdint>
#include "../../../io/CInt.cpp"
#include "../../../io/CFloat.cpp"
#include "../../../io/CSize.cpp"
#include "../../../data_structures/CVector.cpp"
#include "../MethodResult.h"

class CSecantResult {
    CSize count_of_iterations;
    enum MethodResult method_result;
    CVector<CFloat> x;
    CVector<CFloat> y;
    CVector<CFloat> z;
public:

    explicit CSecantResult();

    explicit CSecantResult(enum MethodResult method_result);

    CSize getCountOfIterations();

    enum MethodResult getMethodResult();

    void setMethodResult(enum MethodResult method_result);

    CVector<CFloat> getX();

    CVector<CFloat> getY();

    CVector<CFloat> getZ();

    void append(CFloat &x, CFloat& y, CFloat& z);
};


#endif //VM1_CSECANTRESULT_H
