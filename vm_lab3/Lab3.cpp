//
// Created by R1300-W-8-Stud on 16.03.2023.
//

#include "Lab3.h"
#include "./methods/rectangular/RectMethod.cpp"
#include "../functions/CFunctionManager.cpp"

#define KEY_ESC 27

FILE *Lab3::gnu_pipe;

void Lab3::runFromKeyboard() {
    CFunctionManager manager;
    CFunctionSV *current_function = nullptr;
    current_function = (CFunctionSV *) manager[SINGLE_VARIABLE][1].release();
    CTable result = RectMethod::perform(current_function, MIDDLE_RECTANGULAR, 0, 1, 0.001, 4).getResultData();
    cout << result;
}
