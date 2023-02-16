//
// Created by artem on 16.02.2023.
//

#ifndef VM1_ITERMETHODINFORMATION_H
#define VM1_ITERMETHODINFORMATION_H

#include <cstdint>
#include "../io/CInt.h"
#include "../io/CFloat.h"
#include "../io/CSize.h"
#include "../data_structures/Matrix.h"
#include "../data_structures/CVector.h"


class IterMethodInformation {
    CSize count_of_iterations;
    CVector<CVector<CFloat>> answers;
    CVector<CFloat> eps;
public:
    IterMethodInformation();

    CSize getCountOfIterations();

    CVector<CVector<CFloat>> getAnswers();

    CVector<CFloat> getEps();

    void append(CVector<CFloat> &iteration_answer, CFloat current_eps);
};


#endif //VM1_ITERMETHODINFORMATION_H
