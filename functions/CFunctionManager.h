//
// Created by artem on 23.02.2023.
//

#ifndef VM1_CFUNCTIONMANAGER_H
#define VM1_CFUNCTIONMANAGER_H

#include <cmath>
#include <string>
#include <vector>
#include "./CFunctionMV.cpp"
#include "./CFunctionSV.cpp"
#include "./FunctionType.h"

using namespace std;

class CFunctionManager {
    vector<CFunctionSV*> functions;
    vector<CFunctionMV*> functions_multiple_variables;
public:
    CFunctionManager();
    vector<std::unique_ptr<CFunction>> operator[] (enum FunctionType type);
};


#endif //VM1_CFUNCTIONMANAGER_H
