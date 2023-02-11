#include <iostream>
#include <cstdint>

#define DEBUG_MODE 1

#include <vector>
#include "io/CInt.cpp"
#include "io/CFloat.cpp"
#include "io/CSize.cpp"
#include "data_structures/Matrix.cpp"


using namespace std;

int main() {

    cerr << "Format of usage: " << endl;
    cerr << "N" << endl;
    cerr << "{ a[i][j] } : 1 <= i <= N & 1 <= j <= N" << endl;

    Matrix<CInt> matrix;
    cin >> matrix;
    cout << matrix;

    Matrix<CFloat> matrix1;
    cin >> matrix1;
    cout << matrix1;

    return 0;
}
