//
// Created by artem on 16.02.2023.
//
#include "IterMethodInformation.h"

IterMethodInformation::IterMethodInformation(Matrix<CDouble>& initial_matrix) {
    this->initial_matrix = initial_matrix;
    this->count_of_iterations = 0;
    this->answers = *(new CVector<CVector<CDouble>>(0));
    this->eps = *(new CVector<CDouble>(0));
}

CSize IterMethodInformation::getCountOfIterations() {
    return this->count_of_iterations;
}

CVector<CVector<CDouble>> IterMethodInformation::getAnswers() {
    return this->answers;
}

CVector<CDouble> IterMethodInformation::getEps() {
    return this->eps;
}

Matrix<CDouble> IterMethodInformation::getInitialMatrix() {
    return this->initial_matrix;
}

void IterMethodInformation::append(CVector<CDouble> &iteration_answer, CDouble current_eps) {
    count_of_iterations++;
    answers.push_back(iteration_answer);
    eps.push_back(current_eps);
}

