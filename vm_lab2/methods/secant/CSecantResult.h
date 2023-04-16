//
// Created by artem on 24.02.2023.
//

#ifndef VM1_CSECANTRESULT_H
#define VM1_CSECANTRESULT_H

#include <cstdint>
#include "../../../io/CInt.h"
#include "../../../io/CDouble.h"
#include "../../../io/CSize.h"
#include "../../../data_structures/CVector.h"
#include "../../../data_structures/CTable.h"
#include "../MethodResult.h"
#include "../../methods_data/SingleFunctionMethodData.h"

class CSecantResult {
    CSize count_of_iterations;
    enum MethodResult method_result;
    CVector<CDouble> x;
    CVector<CDouble> y;
    CVector<CDouble> z;
    SingleFunctionMethodData initial_data;
public:

    CSecantResult(SingleFunctionMethodData initial_data);

    CSecantResult(enum MethodResult method_result, SingleFunctionMethodData initial_data);

    CSize getCountOfIterations();

    enum MethodResult getMethodResult();

    void setMethodResult(enum MethodResult method_result);

    CVector<CDouble> getX();

    CVector<CDouble> getY();

    CVector<CDouble> getZ();

    void append(CDouble &x, CDouble& y, CDouble& z);

    SingleFunctionMethodData getInitialData();

    friend ostream& operator <<(ostream& os, CSecantResult& result);

};


#endif //VM1_CSECANTRESULT_H
