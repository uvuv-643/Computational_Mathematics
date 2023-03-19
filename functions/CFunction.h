//
// Created by artem on 24.02.2023.
//

#ifndef VM1_CFUNCTION_H
#define VM1_CFUNCTION_H

#include <functional>
#include <utility>
#include <string>

using namespace std;

class CFunction {
public:
    string function_definition;
    friend ostream &operator<<(ostream &os, const CFunction &function);
};

#endif //VM1_CFUNCTION_H
