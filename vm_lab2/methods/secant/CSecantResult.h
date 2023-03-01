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
#include "../../methods_data/SingleFunctionMethodData.h"

class CSecantResult {
    CSize count_of_iterations;
    enum MethodResult method_result;
    CVector<CFloat> x;
    CVector<CFloat> y;
    CVector<CFloat> z;
    SingleFunctionMethodData initial_data;
public:

    CSecantResult(SingleFunctionMethodData initial_data);

    CSecantResult(enum MethodResult method_result, SingleFunctionMethodData initial_data);

    CSize getCountOfIterations();

    enum MethodResult getMethodResult();

    void setMethodResult(enum MethodResult method_result);

    CVector<CFloat> getX();

    CVector<CFloat> getY();

    CVector<CFloat> getZ();

    void append(CFloat &x, CFloat& y, CFloat& z);

    SingleFunctionMethodData getInitialData();

    friend ostream& operator <<(ostream& os, CSecantResult& result);

};


#endif //VM1_CSECANTRESULT_H
