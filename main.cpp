
#include "vm_lab2/Lab2.cpp"
using namespace std;

int main() {

    string mode;
    cerr << "Do you want to read data from file or from keyboard?" << endl;
    cerr << "Data will be read from file with filepath from env. variable 'SOURCE_PATH'" << endl;
    cerr << "If you want to read data from file print 'file'" << endl;
    cerr << "File must be in following format depends on number of variables: " << endl;
    cerr << "1 #number_of_method #number_of_function #_a #_b #eps" << endl;
    cerr << "2 #number_of_function_1 #number_of_function_2 #x #y #eps" << endl;
    cerr << "To get available methods and functions you should start program with keyboard mode" << endl;
    cin >> mode;
    if (mode == "file") {
        Lab2::runFromFile();
    } else {
        Lab2::runFromKeyboard();
    }
    return 0;
}
