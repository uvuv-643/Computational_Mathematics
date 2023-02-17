
#include "vm_lab1/Lab1.cpp"
using namespace std;

int main() {

    string mode;
    cerr << "Do you want to read data from file?" << endl;
    cerr << "Data will be read from file with filepath from env. variable 'SOURCE_PATH'" << endl;
    cerr << "If you want to read data from file print 'file'" << endl;
    cin >> mode;
    if (mode == "file") {
        Lab1::runFromFile();
    } else {
        Lab1::runFromKeyboard();
    }

    return 0;
}
