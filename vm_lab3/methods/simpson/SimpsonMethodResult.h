//
// Created by R1300-W-8-Stud on 16.03.2023.
//

#ifndef VM1_SIMPSONMETHODRESULT_H
#define VM1_SIMPSONMETHODRESULT_H

#include <stdint.h>
#include "../../../io/CInt.cpp"
#include "../../../io/CFloat.cpp"
#include "../../../io/CSize.cpp"
#include "../../../data_structures/CTable.cpp"
#include "../../../data_structures/CVector.cpp"
#include "../../methods_data/SingleFunctionMethodData.h"
#include "../MethodStatus.h"

class SimpsonMethodResult {
    enum MethodStatus status;
    float square;
    CVector<CSize> intervals;
    CVector<CFloat> squares;
    SingleFunctionMethodData method_data;

public:
    SimpsonMethodResult();
    SimpsonMethodResult(float square);
    SimpsonMethodResult(CVector<CFloat> square, CVector<CSize> number_of_intervals, SingleFunctionMethodData method_data);
    float getSquare();
    CTable getResultData();
};


#endif //VM1_SIMPSONMETHODRESULT_H
