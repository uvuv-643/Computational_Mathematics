//
// Created by artem on 23.02.2023.
//

#include "CTable.h"

ostream &operator<<(ostream &os, CTable &table) {
    size_t table_rows = table.table_data.n;
    size_t table_cols = table.number_of_cols;
    vector<size_t> maximum_size(table_cols);
    for (size_t col = 0; col < table_cols; col++) {
        size_t current_size = table.column_names[col].size();
        for (size_t row = 0; row < table_rows; row++) {
            current_size = max(current_size, table.table_data[row][col].size());
        }
        maximum_size[col] = current_size;
    }
    for (size_t col = 0; col < table_cols; col++) {
        os << "| " << setw(maximum_size[col]) << left << table.column_names[col] << " ";
        if (col == table_cols - 1) {
            os << "|";
        }
    }
    os << endl;

    for (size_t row = 0; row < table_rows; row++) {
        for (size_t col = 0; col < table_cols; col++) {
            os << "| " << setw(maximum_size[col]) << left << table.table_data[row][col] << " ";
            if (col == table_cols - 1) {
                os << "|";
            }
        }
        os << endl;
    }
    return os;
}

bool CTable::insert(string column_title, CVector<CDouble> row) {
    if ((size_t) row.n == (size_t) this->table_data.n) {
        this->column_names.push_back(std::move(column_title));
        for (size_t col = 0; col < (size_t) this->table_data.n; col++) {
            ostringstream oss;
            oss << row[col];
            this->table_data[col].push_back(oss.str());
        }
        this->number_of_cols++;
        return true;
    }
    return false;
}

bool CTable::insert(string column_title, CVector<string> row) {
    if ((size_t) row.n == (size_t) this->table_data.n) {
        this->column_names.push_back(std::move(column_title));
        for (size_t col = 0; col < (size_t) this->table_data.n; col++) {
            this->table_data[col].push_back(row[col]);
        }
        this->number_of_cols++;
        return true;
    }
    return false;
}

bool CTable::insert(string column_title, CVector<CSize> row) {
    if ((size_t) row.n == (size_t) this->table_data.n) {
        this->column_names.push_back(std::move(column_title));
        for (size_t col = 0; col < (size_t) this->table_data.n; col++) {
            ostringstream oss;
            oss << row[col];
            this->table_data[col].push_back(oss.str());
        }
        this->number_of_cols++;
        return true;
    }
    return false;
}

CTable::CTable(size_t n) {
    number_of_rows = n;
    CVector<CVector<string>> table(n);
    this->table_data = table;
    this->number_of_cols = 0;
    vector<CSize> index_vector = vector<CSize>(n);
    size_t i = 1;
    generate(begin(index_vector), end(index_vector), [&] { return i++; });
    this->insert("#", CVector<CSize>(index_vector));
}

CTable::CTable(size_t n, bool with_index) {
    number_of_rows = n;
    CVector<CVector<string>> table(n);
    this->table_data = table;
    this->number_of_cols = 0;
    if (with_index) {
        size_t i = 1;
        vector<CSize> index_vector = vector<CSize>(n);
        generate(begin(index_vector), end(index_vector), [&] { return i++; });
        this->insert("#", CVector<CSize>(index_vector));
    }
}

CTable::CTable() {
    number_of_rows = 0;
}

bool CTable::isEmpty() const {
    return this->number_of_rows == 0;
}

bool CTable::isFilled() const {
    return this->number_of_rows > 0;
}

vector<vector<double>> CTable::getData() {
    vector<vector<double>> data(number_of_rows, vector<double>(number_of_cols - 1));
    for (int i = 0; i < number_of_rows; i++) {
        for (int j = 1; j < number_of_cols; j++) {
            data[i][j - 1] = stod(this->table_data[i][j]);
        }
    }
    return data;
}
