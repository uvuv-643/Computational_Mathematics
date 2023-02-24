//
// Created by artem on 23.02.2023.
//

#ifndef VM1_CHALFDIVIDINGRESULT_H
#define VM1_CHALFDIVIDINGRESULT_H

#include <cstdint>
#include "../../../io/CInt.cpp"
#include "../../../io/CFloat.cpp"
#include "../../../io/CSize.cpp"
#include "../../../data_structures/CVector.cpp"
#include "../MethodResult.h"

class CHalfDividingResult {
    CSize count_of_iterations;
    enum MethodResult method_result;
    CVector<CFloat> answers;
    CVector<CFloat> a;
    CVector<CFloat> b;
public:

    explicit CHalfDividingResult();

    explicit CHalfDividingResult(enum MethodResult method_result);

    CSize getCountOfIterations();

    enum MethodResult getMethodResult();

    CVector<CFloat> getAnswers();

    CVector<CFloat> getA();

    CVector<CFloat> getB();

    void append(CFloat &iteration_answer, CFloat& current_a, CFloat& current_b);

    void setMethodResult(MethodResult result);
};


#endif //VM1_CHALFDIVIDINGRESULT_H
