//
// Created by artem on 15.04.2023.
//

#ifndef VM1_DISCRETEFUNCTION_H
#define VM1_DISCRETEFUNCTION_H

#include <vector>
#include <conio.h>
#include <iostream>
#include "../data_structures/CTable.h"

using namespace std;

class DiscreteFunction {

    size_t number_of_points;
    CVector<CDouble> x;
    CVector<CDouble> y;

public:

    friend ostream &operator<<(ostream &os, const DiscreteFunction &df);

    friend istream &operator>>(istream &is, DiscreteFunction& df);

    size_t getNumberOfPoints() const;

    CVector<CDouble> getX() const;

    CVector<CDouble> getY() const;

    void setNumberOfPoints(size_t number_of_points);

    void setX(CVector<CDouble> x);

    void setY(CVector<CDouble> y);

};


#endif //VM1_DISCRETEFUNCTION_H
