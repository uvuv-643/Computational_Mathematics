//
// Created by artem on 10.02.2023.
//
#pragma once
#ifndef VM1_LAB1_H
#define VM1_LAB1_H

#define INITIAL_EPS 1000.0
#define MAX_NUMBER_OF_ITERATIONS 50
#define ENV_PATH "SOURCE_PATH"

#include <set>
#include <map>
#include <string>
#include "../data_structures/Matrix.h"
#include "../data_structures/CVector.h"
#include "DiagonalDominanceStatus.h"
#include "IterMethodInformation.h"

#include <fstream>

using namespace std;

class Lab1 {
public:
    static enum DiagonalDominanceStatus checkOrApplyDiagonalDominance(Matrix<CDouble>& a, CVector<CDouble>& b);
    static IterMethodInformation& applyIterMethod(Matrix<CDouble>& a, CVector<CDouble>& b, CDouble eps);
    static void runFromFile();
    static void runFromKeyboard();
    static void runFromKeyboardWithGeneration();
    static void outputResult(IterMethodInformation information);
};


#endif //VM1_LAB1_H
