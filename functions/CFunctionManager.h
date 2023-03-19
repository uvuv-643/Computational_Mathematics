//
// Created by artem on 23.02.2023.
//

#ifndef VM1_CFUNCTIONMANAGER_H
#define VM1_CFUNCTIONMANAGER_H

#include <cmath>
#include <string>
#include <vector>
#include <memory>
#include "./CFunctionMV.h"
#include "./CFunctionSV.h"
#include "./FunctionType.h"

using namespace std;

class CFunctionManager {
    vector<CFunctionSV*> functions;
    vector<CFunctionMV*> functions_multiple_variables;
public:
    CFunctionManager();
    vector<CFunctionSV*> getSingleFunctions();
    vector<CFunctionMV*> getMultipleFunctions();
};


#endif //VM1_CFUNCTIONMANAGER_H
