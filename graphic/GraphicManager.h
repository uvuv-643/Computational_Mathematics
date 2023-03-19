//
// Created by artem on 27.02.2023.
//

#ifndef VM1_GRAPHICMANAGER_H
#define VM1_GRAPHICMANAGER_H

#include <cstdio>
#include <cmath>
#include "../functions/CFunctionSV.h"
#include "../functions/CFunctionMV.h"

class GraphicManager {
public:
    static void drawSingleX(FILE* gnu_pipe, CFunctionSV *function, float a, float b);
    static void drawMultipleX(FILE* gnu_pipe, CFunctionSV* f, float a, float b);
    static void drawMultipleXY(FILE* gnu_pipe, CFunctionMV* f, CFunctionMV* g);
    static void drawSingleXY(FILE* gnu_pipe, CFunctionMV* f);
};


#endif //VM1_GRAPHICMANAGER_H
