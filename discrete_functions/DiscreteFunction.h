//
// Created by artem on 15.04.2023.
//

#ifndef VM1_DISCRETEFUNCTION_H
#define VM1_DISCRETEFUNCTION_H

#include <vector>
#include <iostream>
#include "../data_structures/CTable.h"

using namespace std;

class DiscreteFunction {

    size_t number_of_points;
    CVector<CFloat> x;
    CVector<CFloat> y;

public:

    friend ostream &operator<<(ostream &os, const DiscreteFunction &df);

    friend istream &operator>>(istream &is, DiscreteFunction& df);

    size_t getNumberOfPoints() const;

    CVector<CFloat> getX() const;

    CVector<CFloat> getY() const;

    void setNumberOfPoints(size_t number_of_points);

    void setX(CVector<CFloat> x);

    void setY(CVector<CFloat> y);

};


#endif //VM1_DISCRETEFUNCTION_H
