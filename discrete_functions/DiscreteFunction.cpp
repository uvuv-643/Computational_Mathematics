//
// Created by artem on 15.04.2023.
//

#include "DiscreteFunction.h"

ostream &operator<<(ostream &os, const DiscreteFunction &df) {

    CTable data(df.getNumberOfPoints(), true);
    data.insert("X", df.getX());
    data.insert("Y", df.getY());
    os << data << endl;
    return os;
}

istream &operator>>(istream &is, DiscreteFunction &df) {
    CSize number_of_points = 0;

    if (&is == &cin) {
        cerr << "Enter number of points" << endl;
    }

    if (&is == &cin) {
        while (number_of_points < 8 || number_of_points > 12) {
            is >> number_of_points;
            if (number_of_points < 8 || number_of_points > 12) {
                cerr << "Number of points must be in range [8, 12]. Try one more time" << endl;
            }
        }
    } else {
        is >> number_of_points;
        if (number_of_points < 8 || number_of_points > 12) {
            cerr << "Number of points must be in range [8, 12]." << endl;
            getch();
            exit(-1);
        }
    }

    CVector<CDouble> x(number_of_points);
    CVector<CDouble> y(number_of_points);
    if (&is == &cin) {
        cerr << "Enter x_1, x_2, ..., x_n" << endl;
    }
    is >> x;
    if (&is == &cin) {
        cerr << "Enter y_1, y_2, ..., y_n" << endl;
    }
    is >> y;
    df.setNumberOfPoints(number_of_points);
    df.setX(x);
    df.setY(y);
    return is;
}

size_t DiscreteFunction::getNumberOfPoints() const {
    return this->number_of_points;
}

CVector<CDouble> DiscreteFunction::getX() const {
    return this->x;
}

CVector<CDouble> DiscreteFunction::getY() const {
    return this->y;
}

void DiscreteFunction::setNumberOfPoints(size_t number_of_points) {
    this->number_of_points = number_of_points;
}

void DiscreteFunction::setX(CVector<CDouble> x) {
    this->x = x;
}

void DiscreteFunction::setY(CVector<CDouble> y) {
    this->y = y;
}
