//
// Created by artem on 16.02.2023.
//
#include "IterMethodInformation.h"

IterMethodInformation::IterMethodInformation(Matrix<CFloat>& initial_matrix) {
    this->initial_matrix = initial_matrix;
    this->count_of_iterations = 0;
    this->answers = *(new CVector<CVector<CFloat>>(0));
    this->eps = *(new CVector<CFloat>(0));
}

CSize IterMethodInformation::getCountOfIterations() {
    return this->count_of_iterations;
}

CVector<CVector<CFloat>> IterMethodInformation::getAnswers() {
    return this->answers;
}

CVector<CFloat> IterMethodInformation::getEps() {
    return this->eps;
}

Matrix<CFloat> IterMethodInformation::getInitialMatrix() {
    return this->initial_matrix;
}

void IterMethodInformation::append(CVector<CFloat> &iteration_answer, CFloat current_eps) {
    count_of_iterations++;
    answers.push_back(iteration_answer);
    eps.push_back(current_eps);
}

