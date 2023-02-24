
#include "vm_lab2/Lab2.cpp"
using namespace std;

int main() {

    string mode;
    cerr << "Do you want to read data from file or auto generated?" << endl;
    cerr << "Data will be read from file with filepath from env. variable 'SOURCE_PATH'" << endl;
    cerr << "If you want to read data from file print 'file'" << endl;
    cerr << "If you want to automatically generate matrix and vector, print 'generate'" << endl;
    cin >> mode;
    if (mode == "file") {
        Lab2::runFromFile();
    } else {
        Lab2::runFromKeyboard();
    }

    return 0;
}
