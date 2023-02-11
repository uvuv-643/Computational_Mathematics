//
// Created by artem on 10.02.2023.
//

#include "Lab1.h"
#include "DiagonalDominanceStatus.h"

#define coutv(v) for (int jj = 0; jj < (v).size(); ++jj) cout << v[jj] << " "; cout << endl;
#define coutvv(v) for (int i = 0; i < (v).size(); ++i) {for (int j = 0; j < (v[i]).size(); ++j) cout << v[i][j] << ' '; cout << endl;}
#define coutp(v) for (int i = 0; i < (v).size(); ++i) cout << v[i].first << " " << v[i].second << endl; cout << endl;


void Lab1::runFromKeyboard() {

    Matrix<CFloat> a;
    CFloat eps;

    if (std::getenv("DEBUG_MODE")) {
        cerr << "> Enter matrix A below following instruction" << endl;
    }
    cin >> a;
    size_t n = a.n;

    CVector<CFloat> b(n);
    if (std::getenv("DEBUG_MODE")) {
        cerr << "> Enter vector B below following instruction" << endl;
    }
    cin >> b;

    if (std::getenv("DEBUG_MODE")) {
        cerr << "> Enter eps below" << endl;
    }
    cin >> eps;

    // checking possibility of diagonal maximum
    enum DiagonalDominanceStatus diagonal_dominance_status = checkOrApplyDiagonalDominance(a);
    cout << diagonal_dominance_status << " ";

    Matrix<CFloat> c(a.n);

}

void Lab1::runFromFile() {

    ifstream fs;
    fs.open(std::getenv("SOURCE_PATH"));

    Matrix<CFloat> a;
    CFloat eps;

    if (std::getenv("DEBUG_MODE")) {
        cerr << "> Enter matrix A below following instruction" << endl;
    }
    fs >> a;
    size_t n = a.n;

    CVector<CFloat> b(n);
    if (std::getenv("DEBUG_MODE")) {
        cerr << "> Enter vector B below following instruction" << endl;
    }
    fs >> b;

    if (std::getenv("DEBUG_MODE")) {
        cerr << "> Enter eps below" << endl;
    }
    fs >> eps;

    // checking possibility of diagonal maximum
    enum DiagonalDominanceStatus diagonal_dominance_status = checkOrApplyDiagonalDominance(a);
    Matrix<CFloat> c(a.n);
    fs.close();
}

enum DiagonalDominanceStatus Lab1::checkOrApplyDiagonalDominance(Matrix<CFloat> &a) {
    size_t n = a.n;
    set<size_t> good_indexes;
    map<size_t, size_t> maximums_by_indexes;
    for (size_t row = 0; row < n; row++) {
        maximums_by_indexes[row] = -1;
    }
    for (size_t row = 0; row < n; row++) {
        CFloat sum_in_row = 0;
        CFloat maximum_element_in_row = a[row][0];
        size_t maximum_element_in_row_index = 0;
        for (size_t col = 0; col < n; col++) {
            sum_in_row += a[row][col];
            if (a[row][col] > maximum_element_in_row) {
                maximum_element_in_row_index = col;
                maximum_element_in_row = a[row][col];
            }
        }
        maximums_by_indexes[row] = maximum_element_in_row_index;
        if (sum_in_row - maximum_element_in_row <= maximum_element_in_row) {
            good_indexes.insert(maximum_element_in_row_index);
        }
    }
    if (good_indexes.size() != n) {
        return DIAGONAL_DOMINANCE_IS_NOT_REACHABLE_T;
    } else {
        vector<pair<size_t, size_t>> have_to_be_swapped = {};
        for (size_t current_column = 0; current_column < n; current_column++) {
            if (current_column != maximums_by_indexes[current_column]) {
                bool found_pair_to_current_column = false;
                for (size_t found_column = current_column + 1; found_column < n; found_column++) {
                    if (maximums_by_indexes[found_column] == current_column) {
                        have_to_be_swapped.emplace_back(current_column, found_column);
                        maximums_by_indexes[found_column] = maximums_by_indexes[current_column];
                        maximums_by_indexes[current_column] = current_column;
                        found_pair_to_current_column = true;
                        break;
                    }
                }
                if (!found_pair_to_current_column) {
                    return DIAGONAL_DOMINANCE_IS_NOT_REACHABLE;
                }
            }
        }
        for (pair<size_t, size_t> swapped_elements : have_to_be_swapped) {
            for (size_t col = 0; col < n; col++) {
                swap(a[swapped_elements.first][col], a[swapped_elements.second][col]);
            }
        }
        cout << a;
    }
    return DIAGONAL_DOMINANCE_WAS_REACHED;
}
