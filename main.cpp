
#include "vm_lab1/Lab1.h"
#include "vm_lab2/Lab2.h"
#include "vm_lab3/Lab3.h"

using namespace std;

int main() {

    string mode;
    cerr << "Do you want to read data from file or from keyboard?" << endl;
    cerr << "Data will be read from file with filepath from env. variable 'SOURCE_PATH'" << endl;
    cerr << "If you want to read data from file print 'file'" << endl;
    cerr << "File must be in following format depends on number of variables: " << endl;
    cerr << "#number_of_method #number_of_function #_a #_b #eps" << endl;
    cerr << "To get available methods and functions you should start program with keyboard mode" << endl;
    cin >> mode;
    if (mode == "file") {
        Lab3::runFromFile();
    } else {
        Lab3::runFromKeyboard();
    }
    return 0;

    return 0;
}
