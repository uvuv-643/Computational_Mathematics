//
// Created by artem on 15.04.2023.
//

#include "Lab4.h"

void Lab4::runFromFile() {

}

void Lab4::runFromKeyboard() {

    DiscreteFunction df;
    cin >> df;
    cout << df;

    PolynomialRegression polynomialRegression(2);
    CVector<CFloat> answer = polynomialRegression.performMethod(df.getNumberOfPoints(), df.getX(), df.getY());
    for (int i = 0; i < (size_t) answer.n; i++) {
        cout << answer[i] << " * x^" << i << " ";
        if (i + 1 < (size_t) answer.n) {
            cout << "+ ";
        }
    }
    getch();

}
