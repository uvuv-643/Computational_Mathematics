//
// Created by artem on 10.02.2023.
//
#pragma once
#ifndef VM1_LAB1_H
#define VM1_LAB1_H

#include <set>
#include <map>
#include "../io/CInt.cpp"
#include "../io/CFloat.cpp"
#include "../io/CSize.cpp"
#include "../data_structures/Matrix.cpp"
#include "../data_structures/CVector.cpp"
#include "DiagonalDominanceStatus.h"

#include <fstream>

using namespace std;

class Lab1 {
public:
    static enum DiagonalDominanceStatus checkOrApplyDiagonalDominance(Matrix<CFloat>& a);
    static void runFromKeyboard();
    static void runFromFile();
};


#endif //VM1_LAB1_H
