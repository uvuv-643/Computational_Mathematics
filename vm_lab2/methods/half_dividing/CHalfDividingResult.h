//
// Created by artem on 23.02.2023.
//

#ifndef VM1_CHALFDIVIDINGRESULT_H
#define VM1_CHALFDIVIDINGRESULT_H

#include <cstdint>
#include "../../../io/CInt.h"
#include "../../../io/CFloat.h"
#include "../../../io/CSize.h"
#include "../../../data_structures/CVector.h"
#include "../../../data_structures/CTable.h"
#include "../MethodResult.h"
#include "../../methods_data/SingleFunctionMethodData.h"

class CHalfDividingResult {
    CSize count_of_iterations;
    enum MethodResult method_result;
    CVector<CFloat> answers;
    CVector<CFloat> a;
    CVector<CFloat> b;
    SingleFunctionMethodData initial_data;
public:

    CHalfDividingResult(SingleFunctionMethodData initial_data);

    CHalfDividingResult(enum MethodResult method_result, SingleFunctionMethodData initial_data);

    CSize getCountOfIterations();

    enum MethodResult getMethodResult();

    CVector<CFloat> getAnswers();

    CVector<CFloat> getA();

    CVector<CFloat> getB();

    void append(CFloat &iteration_answer, CFloat& current_a, CFloat& current_b);

    void setMethodResult(MethodResult result);

    SingleFunctionMethodData getInitialData();

    friend ostream& operator <<(ostream& os, CHalfDividingResult& result);

};


#endif //VM1_CHALFDIVIDINGRESULT_H
