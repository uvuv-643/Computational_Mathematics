//
// Created by R1300-W-8-Stud on 16.03.2023.
//

#ifndef VM1_RECTMETHODRESULT_H
#define VM1_RECTMETHODRESULT_H

#include <cstdint>
#include "../../../io/CInt.h"
#include "../../../io/CFloat.h"
#include "../../../io/CSize.h"
#include "../../../data_structures/CTable.h"
#include "../../../data_structures/CVector.h"
#include "../../methods_data/SingleFunctionIntegralMethodData.h"
#include "../MethodStatus.h"

class TrapezeMethodResult {
    enum MethodStatus status;
    float square;
    CVector<CSize> intervals;
    CVector<CFloat> squares;
    SingleFunctionIntegralMethodData method_data;

public:
    TrapezeMethodResult();
    TrapezeMethodResult(float square);
    TrapezeMethodResult(CVector<CFloat> square, CVector<CSize> number_of_intervals, SingleFunctionIntegralMethodData method_data);
    float getSquare();
    CTable getResultData();
};


#endif //VM1_RECTMETHODRESULT_H
