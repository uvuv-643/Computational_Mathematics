//
// Created by artem on 23.02.2023.
//

#ifndef VM1_CTABLE_H
#define VM1_CTABLE_H

#include <cstdint>
#include <string>
#include <utility>
#include "./CVector.h"
#include "../io/CDouble.h"
#include "../io/CSize.h"
#include "../io/CInt.h"

using namespace std;

class CTable {
    CVector<CVector<string>> table_data;
    CVector<string> column_names;
    size_t number_of_cols;
    size_t number_of_rows;
public:

    explicit CTable();

    explicit CTable(size_t n);

    CTable(size_t n, bool with_index);

    bool insert(string column_title, CVector<CDouble> row);

    bool insert(string column_title, CVector<string> row);

    bool insert(string column_title, CVector<CSize> row);

    friend ostream &operator<<(ostream &os, CTable &table);

    bool isEmpty() const;

    bool isFilled() const;

};


#endif //VM1_CTABLE_H
