#include <iostream>
#include <cstdint>
#include <vector>
#include "io/CInt.cpp"
#include "io/CFloat.cpp"
#include "io/CSize.cpp"

using namespace std;

int main() {

    cout << "Format of usage: " << endl;
    cout << "N" << endl;
    cout << "{ a[i][j] } : 1 <= i <= N & 1 <= j <= N" << endl;
    CSize n;
    cin >> n;

    CFloat a, b, c;
    cin >> a >> b >> c;
    cout << a << " " << b << " " << c << endl;

    vector<vector<CInt>> matrix(n, vector<CInt>(n));


    return 0;
}
