//
// Created by artem on 10.02.2023.
//

#include "Lab1.h"

void Lab1::runFromKeyboard() {

    Matrix<CFloat> a;
    CFloat eps;

    if (&is == &cin) {
        cerr << "> Enter matrix A below following instruction" << endl;
    }
    cin >> a;
    size_t n = a.n;

    CVector<CFloat> b(n);
    if (&is == &cin) {
        cerr << "> Enter vector B below following instruction" << endl;
    }
    cin >> b;

    if (&is == &cin) {
        cerr << "> Enter eps below" << endl;
    }
    cin >> eps;

    IterMethodInformation answer = applyIterMethod(a, b, eps);
    outputResult(answer);

}

void Lab1::runFromFile() {

    string file_path = std::getenv(ENV_PATH);
    if (file_path.empty()) {
        cerr << "Not found env. variable '" << ENV_PATH << "'" << endl;
        return;
    }
    ifstream fs;
    fs.open(std::getenv(ENV_PATH));
    if (fs.fail()) {
        cerr << "File not found. Make sure that it exists" << endl;
        return;
    }

    Matrix<CFloat> a;
    CFloat eps;
    fs >> a;
    size_t n = a.n;
    CVector<CFloat> b(n);
    fs >> b;

    if (!fs.eof()) {
        fs >> eps;
        IterMethodInformation answer = applyIterMethod(a, b, eps);
        outputResult(answer);
    } else {
        cerr << "Something wrong with file. Consider you are using correct format of file" << endl;
    }
    fs.close();

}

void Lab1::outputResult(IterMethodInformation information) {
    Matrix<CFloat> initial_matrix = information.getInitialMatrix();
    if (information.getCountOfIterations() > 0) {
        CVector<CVector<CFloat>> iterations = information.getAnswers();
        CVector<CFloat> errors = information.getEps();
        cout << "Diagonal domination was reached" << endl;
        cout << "Updated matrix A: " << endl;
        cout << initial_matrix << endl;
        cout << "Number of iterations: " << information.getCountOfIterations() << endl;
        cout << "Iterations: " << endl;
        for (size_t k = 0; k < (size_t) information.getCountOfIterations(); k++) {
            cout << "k = " << k << " | ";
            cout << iterations[k] << " | ";
            cout << "eps = " << errors[k] << endl;
        }
    } else {
        cerr << "There is no diagonal dominance, unable to solve system" << endl;
        cerr << initial_matrix << endl;
    }
}

enum DiagonalDominanceStatus Lab1::checkOrApplyDiagonalDominance(Matrix<CFloat> &a, CVector<CFloat> &b) {
    size_t n = a.n;
    set<size_t> good_indexes;
    map<size_t, size_t> maximums_by_indexes;
    for (size_t row = 0; row < n; row++) {
        maximums_by_indexes[row] = -1;
    }
    for (size_t row = 0; row < n; row++) {
        CFloat sum_in_row = 0;
        CFloat maximum_element_in_row = abs(a[row][0]);
        size_t maximum_element_in_row_index = 0;
        for (size_t col = 0; col < n; col++) {
            sum_in_row += abs(a[row][col]);
            if (abs(a[row][col]) > maximum_element_in_row) {
                maximum_element_in_row_index = col;
                maximum_element_in_row = abs(a[row][col]);
            }
        }
        maximums_by_indexes[row] = maximum_element_in_row_index;
        if (sum_in_row - maximum_element_in_row <= maximum_element_in_row) {
            good_indexes.insert(maximum_element_in_row_index);
        }
    }
    if (good_indexes.size() != n) {
        return DIAGONAL_DOMINANCE_IS_NOT_REACHABLE;
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
        for (pair<size_t, size_t> swapped_elements: have_to_be_swapped) {
            swap(b[swapped_elements.first], b[swapped_elements.second]);
            for (size_t col = 0; col < n; col++) {
                swap(a[swapped_elements.first][col], a[swapped_elements.second][col]);
            }
        }
        if (have_to_be_swapped.empty()) {
            return DIAGONAL_DOMINANCE_INITIALLY_PRESENT;
        }
        return DIAGONAL_DOMINANCE_WAS_REACHED;
    }
}

IterMethodInformation &Lab1::applyIterMethod(Matrix<CFloat> &a, CVector<CFloat> &b, CFloat eps) {
    enum DiagonalDominanceStatus dominance_status = checkOrApplyDiagonalDominance(a, b);
    auto *answer = new IterMethodInformation(a);
    if (dominance_status >= 0) {
        size_t k = 1;
        size_t n = a.n;
        vector<vector<float>> dp(1, vector<float>(n));
        float current_eps = INITIAL_EPS;
        for (size_t i = 0; i < n; i++) {
            dp[0][i] = b[i] / a[i][i];
        }
        while (k < MAX_NUMBER_OF_ITERATIONS && current_eps >= eps) {
            vector<float> new_solution(n);
            dp.emplace_back(new_solution);
            for (size_t i = 0; i < n; i++) {
                dp[k][i] += b[i] / a[i][i];
                for (size_t j = 0; j < n; j++) {
                    if (i != j) {
                        dp[k][i] -= (a[i][j] * dp[k - 1][j] / a[i][i]);
                    }
                }
            }
            float maximum_difference = 0;
            for (size_t i = 0; i < n; i++) {
                maximum_difference = max(maximum_difference, abs(dp[k][i] - dp[k - 1][i]));
            }
            current_eps = maximum_difference;
            k++;
        }
        for (size_t s = 0; s < dp.size(); s++) {
            float maximum_difference = 0;
            CVector<CFloat> current(n);
            for (size_t i = 0; i < n; i++) {
                current[i] = dp[s][i];
            }
            if (s != 0) {
                for (size_t i = 0; i < n; i++) {
                    maximum_difference = max(maximum_difference, abs(dp[s][i] - dp[s - 1][i]));
                }
                answer->append(current, maximum_difference);
            } else {
                answer->append(current, INITIAL_EPS);
            }
        }
    }
    return *answer;
}

