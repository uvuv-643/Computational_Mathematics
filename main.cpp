
#include "vm_lab1/Lab1.h"
#include "vm_lab2/Lab2.h"
#include "vm_lab3/Lab3.h"
#include "vm_lab4/Lab4.h"

using namespace std;

int lab3() {

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

}

int lab4() {

    string mode;
    cerr << "Do you want to read data from file or from keyboard?" << endl;
    cerr << "Data will be read from file with filepath from env. variable 'SOURCE_PATH_INPUT'" << endl;
    cerr << "If you want to read data from file print 'file'" << endl;
    cerr << "File must be in following format depends on number of variables: " << endl;
    cerr << "#n" << endl;
    cerr << "#x_0, #x_1, ..., #x_n" << endl;
    cerr << "#y_0, #y_1, ..., #y_n" << endl;
    cerr << "#file" << endl << endl;

    cin >> mode;
    if (mode == "file") {
        Lab4::runFromFile();
    } else {
        Lab4::runFromKeyboard();
    }

    getch();

    fclose(Lab4::gnu_pipe);

    return 0;

}

int main() {

    return lab4();

}
