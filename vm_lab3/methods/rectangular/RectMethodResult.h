//
// Created by R1300-W-8-Stud on 16.03.2023.
//

#ifndef VM1_RECTMETHODRESULT_H
#define VM1_RECTMETHODRESULT_H

#include <stdint.h>
#include "../../../io/CInt.cpp"
#include "../../../io/CFloat.cpp"
#include "../../../io/CSize.cpp"
#include "../../../data_structures/CTable.cpp"
#include "../../../data_structures/CVector.cpp"
#include "../../methods_data/SingleFunctionMethodData.h"

class RectMethodResult {
    float square;
    size_t number_of_intervals;
    SingleFunctionMethodData method_data;

public:
    RectMethodResult();
    RectMethodResult(float square);
    RectMethodResult(float square, size_t number_of_intervals, SingleFunctionMethodData method_data);
    float getSquare();
    CTable getResultData();
};


#endif //VM1_RECTMETHODRESULT_H
