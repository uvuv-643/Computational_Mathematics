//
// Created by artem on 15.04.2023.
//

#include "DiscreteFunction.h"

#include <utility>

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
        if (df.getType() == "lab4") {
            while (number_of_points < 8 || number_of_points > 12) {
                is >> number_of_points;
                if (number_of_points < 8 || number_of_points > 12) {
                    cerr << "Number of points must be in range [8, 12]. Try one more time" << endl;
                }
            }
        } else {
            while (number_of_points < 2 || number_of_points > 12) {
                is >> number_of_points;
                if (number_of_points < 2 || number_of_points > 12) {
                    cerr << "Number of points must be in range [2, 12]. Try one more time" << endl;
                }
            }
        }
    } else {
        if (df.getType() == "lab4") {
            is >> number_of_points;
            if (number_of_points < 8 || number_of_points > 12) {
                cerr << "Number of points must be in range [8, 12]." << endl;
                getch();
                exit(-1);
            }
        } else {
            is >> number_of_points;
            if (number_of_points < 2 || number_of_points > 12) {
                cerr << "Number of points must be in range [2, 12]." << endl;
                getch();
                exit(-1);
            }
        }
    }

    CVector<CDouble> x(number_of_points);
    CVector<CDouble> y(number_of_points);
    if (&is == &cin) {
        while (true) {
            if (&is == &cin) {
                cerr << "Enter x_1, x_2, ..., x_n" << endl;
            }
            is >> x;
            set<double> unique_points;
            for (size_t i = 0; i < (size_t) x.n; i++) {
                unique_points.insert(x[i]);
            }
            bool is_ok = true;
            double dx = x[1] - x[0];
            for (size_t i = 1; i < (size_t) x.n; i++) {
                if (abs(x[i] - x[i - 1] - dx) > 0.01) is_ok = false;
            }
            if (unique_points.size() != (size_t) x.n) {
                cout << "All points must be unique, input one more time" << endl;
            } else {
                if (!is_ok) {
                    cout << "All points must be with fixed delta x, input one more time" << endl;
                } else {
                    break;
                }
            }
        }
    } else {
        is >> x;
        set<double> unique_points;
        for (size_t i = 0; i < (size_t) x.n; i++) {
            unique_points.insert(x[i]);
        }

        bool is_ok = true;
        double dx = x[1] - x[0];
        for (size_t i = 1; i < (size_t) x.n; i++) {
            if (abs(x[i] - x[i - 1] - dx) > 0.01) is_ok = false;
        }

        if (unique_points.size() != (size_t) x.n) {
            cout << "All points must be unique" << endl;
            getch();
            exit(-1);
        }
        if (!is_ok) {
            cout << "All points must be with fixed delta x, input one more time" << endl;
            getch();
            exit(-1);
        }
    }

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

DiscreteFunction::DiscreteFunction(string _type) {
    this->type = std::move(_type);
}

string DiscreteFunction::getType() {
    return this->type;
}
