//
// Created by artem on 10.02.2023.
//
#pragma once
#ifndef VM1_LAB1_H
#define VM1_LAB1_H

#define INITIAL_EPS 1000.0
#define MAX_NUMBER_OF_ITERATIONS 50

#include <set>
#include <map>
#include <string>
#include "../io/CInt.cpp"
#include "../io/CFloat.cpp"
#include "../io/CSize.cpp"
#include "../data_structures/Matrix.cpp"
#include "../data_structures/CVector.cpp"
#include "DiagonalDominanceStatus.h"
#include "IterMethodInformation.cpp"

#include <fstream>

using namespace std;

class Lab1 {
public:
    static enum DiagonalDominanceStatus checkOrApplyDiagonalDominance(Matrix<CFloat>& a, CVector<CFloat>& b);
    static IterMethodInformation& applyIterMethod(Matrix<CFloat>& a, CVector<CFloat>& b, CFloat eps);
    static void runFromKeyboard();
    static void runFromFile();
    static void outputResult(IterMethodInformation information);
};


#endif //VM1_LAB1_H
