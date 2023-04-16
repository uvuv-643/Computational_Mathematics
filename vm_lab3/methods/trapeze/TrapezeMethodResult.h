//
// Created by R1300-W-8-Stud on 16.03.2023.
//

#ifndef VM1_RECTMETHODRESULT_H
#define VM1_RECTMETHODRESULT_H

#include <cstdint>
#include "../../../io/CInt.h"
#include "../../../io/CDouble.h"
#include "../../../io/CSize.h"
#include "../../../data_structures/CTable.h"
#include "../../../data_structures/CVector.h"
#include "../../methods_data/SingleFunctionIntegralMethodData.h"
#include "../MethodStatus.h"

class TrapezeMethodResult {
    enum MethodStatus status;
    double square;
    CVector<CSize> intervals;
    CVector<CDouble> squares;
    SingleFunctionIntegralMethodData method_data;

public:
    TrapezeMethodResult();
    TrapezeMethodResult(double square);
    TrapezeMethodResult(CVector<CDouble> square, CVector<CSize> number_of_intervals, SingleFunctionIntegralMethodData method_data);
    double getSquare();
    CTable getResultData();
};


#endif //VM1_RECTMETHODRESULT_H
