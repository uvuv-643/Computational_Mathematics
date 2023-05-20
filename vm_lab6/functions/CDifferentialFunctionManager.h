//
// Created by K49-R355-M11 on 20.05.2023.
//

#ifndef COMPUTATIONAL_MATHEMATICS_CDIFFERENTIALFUNCTIONMANAGER_H
#define COMPUTATIONAL_MATHEMATICS_CDIFFERENTIALFUNCTIONMANAGER_H

#include <cmath>
#include <vector>
#include "CDifferentialFunction.h"

using namespace std;

class CDifferentialFunctionManager {

    vector<CDifferentialFunction*> functions;

public:

    CDifferentialFunctionManager();

    CDifferentialFunction* get_function(int index);

};


#endif //COMPUTATIONAL_MATHEMATICS_CDIFFERENTIALFUNCTIONMANAGER_H
