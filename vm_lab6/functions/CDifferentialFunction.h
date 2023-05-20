//
// Created by K49-R355-M11 on 20.05.2023.
//

#ifndef COMPUTATIONAL_MATHEMATICS_CDIFFERENTIALFUNCTION_H
#define COMPUTATIONAL_MATHEMATICS_CDIFFERENTIALFUNCTION_H

#include <string>

using namespace std;

class CDifferentialFunction {

public:

    string function_definition;

    double (*f)(double, double);
    double (*target)(double);

    CDifferentialFunction(string name, double f(double, double), double target(double));

};


#endif //COMPUTATIONAL_MATHEMATICS_CDIFFERENTIALFUNCTION_H
