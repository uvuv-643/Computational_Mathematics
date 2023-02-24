//
// Created by artem on 23.02.2023.
//

#ifndef VM1_CFUNCTIONMANAGER_H
#define VM1_CFUNCTIONMANAGER_H

#include <cmath>
#include <string>
#include <vector>

using namespace std;

class CFunctionManager {
    vector<CFunction*> functions;
public:
    CFunctionManager();
    CFunction* operator[](size_t i);
};


#endif //VM1_CFUNCTIONMANAGER_H
