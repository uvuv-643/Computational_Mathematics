//
// Created by artem on 16.02.2023.
//

#ifndef VM1_ITERMETHODINFORMATION_H
#define VM1_ITERMETHODINFORMATION_H

#include <cstdint>
#include "../io/CInt.h"
#include "../io/CDouble.h"
#include "../io/CSize.h"
#include "../data_structures/Matrix.h"
#include "../data_structures/CVector.h"


class IterMethodInformation {
    CSize count_of_iterations;
    CVector<CVector<CDouble>> answers;
    CVector<CDouble> eps;
    Matrix<CDouble> initial_matrix;
public:

    explicit IterMethodInformation(Matrix<CDouble> &initial_matrix);

    CSize getCountOfIterations();

    CVector<CVector<CDouble>> getAnswers();

    Matrix<CDouble> getInitialMatrix();

    CVector<CDouble> getEps();

    void append(CVector<CDouble> &iteration_answer, CDouble current_eps);
};


#endif //VM1_ITERMETHODINFORMATION_H
