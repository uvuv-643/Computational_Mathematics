//
// Created by artem on 24.02.2023.
//

#ifndef VM1_CITERATIONSRESULT_H
#define VM1_CITERATIONSRESULT_H

#include <cstdint>
#include "../../../io/CInt.h"
#include "../../../io/CDouble.h"
#include "../../../io/CSize.h"
#include "../../../data_structures/CVector.h"
#include "../../../data_structures/CTable.h"
#include "../MethodResult.h"
#include "../../methods_data/SingleFunctionMethodData.h"


class CIterationsResult {
    CSize count_of_iterations;
    enum MethodResult method_result;
    CVector<CDouble> x;
    CVector<CDouble> y;
    SingleFunctionMethodData initial_data;
public:

    CIterationsResult(SingleFunctionMethodData initial_data);

    CIterationsResult(enum MethodResult method_result, SingleFunctionMethodData initial_data);

    CSize getCountOfIterations();

    enum MethodResult getMethodResult();

    void setMethodResult(enum MethodResult method_result);

    CVector<CDouble> getX();

    CVector<CDouble> getY();

    void append(CDouble &x, CDouble &y);

    SingleFunctionMethodData getInitialData();

    friend ostream& operator <<(ostream& os, CIterationsResult& result);

};


#endif //VM1_CITERATIONSRESULT_H
