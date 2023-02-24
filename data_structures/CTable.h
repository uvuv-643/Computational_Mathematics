//
// Created by artem on 23.02.2023.
//

#ifndef VM1_CTABLE_H
#define VM1_CTABLE_H

#include <stdint.h>
#include "./CVector.cpp"
#include "../io/CFloat.cpp"
#include "../io/CSize.cpp"
#include "../io/CInt.cpp"
#include <string>

using namespace std;

class CTable {
    CVector<CVector<string>> table_data;
    CVector<string> column_names;
    size_t number_of_cols;
public:
    explicit CTable(size_t n);

    bool insert(string column_title, CVector<CFloat> row);

    bool insert(string column_title, CVector<string> row);

    bool insert(string column_title, CVector<CSize> row);

    friend ostream &operator<<(ostream &os, CTable &table);

};


#endif //VM1_CTABLE_H
