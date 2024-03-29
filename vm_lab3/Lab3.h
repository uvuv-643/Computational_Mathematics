//
// Created by R1300-W-8-Stud on 16.03.2023.
//

#ifndef VM1_LAB3_H
#define VM1_LAB3_H

#define ENV_PATH "SOURCE_PATH"

#include <cstdio>
#include "cmath"
#include <conio.h>
#include <fstream>
#include <iostream>
#include "../graphic/GraphicManager.h"
#include "./methods/simpson/SimpsonMethod.h"
#include "./methods/trapeze/TrapezeMethod.h"
#include "./methods/rectangular/RectMethod.h"
#include "../functions/CFunctionManager.h"
#include "./methods_data/SingleFunctionIntegralMethodData.h"

using namespace std;

class Lab3 {
    static FILE* gnu_pipe;
public:
    static void runFromFile();
    static void runFromKeyboard();
    static SingleFunctionIntegralMethodData inputDataSingleFunction(CFunctionManager manager);
};


#endif //VM1_LAB3_H
