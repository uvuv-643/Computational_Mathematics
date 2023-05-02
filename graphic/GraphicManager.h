//
// Created by artem on 27.02.2023.
//

#ifndef VM1_GRAPHICMANAGER_H
#define VM1_GRAPHICMANAGER_H

#include <cstdio>
#include <vector>
#include <iterator>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "../data_structures/CVector.h"
#include "../functions/CFunctionSV.h"
#include "../functions/CFunctionMV.h"

class GraphicManager {
public:
    static void drawSingleX(FILE* gnu_pipe, CFunctionSV *function, double a, double b);
    static void drawSingleX(FILE* gnu_pipe, string function_definition, double a, double b);
    static void drawSingleXWithPoints(FILE* gnu_pipe, string function_definition, vector<CDouble>& x, vector<CDouble>& y, double a, double b);
    static void drawMultipleX(FILE* gnu_pipe, CFunctionSV* f, double a, double b);
    static void drawMultipleXY(FILE* gnu_pipe, CFunctionMV* f, CFunctionMV* g);
    static void drawSingleXY(FILE* gnu_pipe, CFunctionMV* f);
};


#endif //VM1_GRAPHICMANAGER_H
