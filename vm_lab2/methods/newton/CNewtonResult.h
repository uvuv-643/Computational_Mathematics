//
// Created by artem on 26.02.2023.
//

#ifndef VM1_CNEWTONRESULT_H
#define VM1_CNEWTONRESULT_H

#include <cstdint>
#include "../../../io/CInt.h"
#include "../../../io/CFloat.h"
#include "../../../io/CSize.h"
#include "../../../data_structures/CVector.h"
#include "../../../data_structures/CTable.h"
#include "../MethodResult.h"
#include "../../methods_data/MultipleFunctionMethodData.h"

class CNewtonResult {
    CSize count_of_iterations;
    enum MethodResult method_result;
    CVector<CFloat> x;
    CVector<CFloat> y;
    CVector<CFloat> dx;
    CVector<CFloat> dy;
    MultipleFunctionMethodData initial_data;
public:

    CNewtonResult(MultipleFunctionMethodData initial_data);

    CNewtonResult(enum MethodResult method_result, MultipleFunctionMethodData initial_data);

    CSize getCountOfIterations();

    enum MethodResult getMethodResult();

    void setMethodResult(enum MethodResult method_result);

    CVector<CFloat> getX();

    CVector<CFloat> getY();

    CVector<CFloat> getDX();

    CVector<CFloat> getDY();

    void append(CFloat &x, CFloat& y, CFloat& dx, CFloat& dy);

    MultipleFunctionMethodData getInitialData();

    friend ostream& operator <<(ostream& os, CNewtonResult& result);

};


#endif //VM1_CNEWTONRESULT_H
