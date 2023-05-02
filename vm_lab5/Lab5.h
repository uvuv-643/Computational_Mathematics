//
// Created by artem on 01.05.2023.
//

#ifndef VM1_LAB5_H
#define VM1_LAB5_H

#define ENV_PATH_INPUT "SOURCE_PATH_INPUT"

#include <iostream>
#include "../discrete_functions/DiscreteFunction.h"
#include "methods/Gs.h"
#include "methods/Lg.h"
#include "methods/St.h"
#include "../graphic/GraphicManager.h"
#include "../functions/CFunctionManager.h"


using namespace std;

class Lab5 {

public:
    static FILE* gnu_pipe;
    static void runFromKeyboard();
    static void runFromFile();
    static void runFromFunctions();
};


#endif //VM1_LAB5_H
