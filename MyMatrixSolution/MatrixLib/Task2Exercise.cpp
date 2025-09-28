#include "Task2Exercise.h"
#include <cmath>

namespace miit::algebra {

Task2Exercise::Task2Exercise(Matrix mat) : Exercise(std::move(mat)), result(0) {}

bool Task2Exercise::hasEvenFirstAndLast(int value) {
    int n = std::abs(value);
    if (n == 0) return false;
    int last = n % 10;
    int first = n;
    while (first >= 10) first /= 10;
    return (first % 2 == 0) && (last % 2 == 0);
}

size_t Task2Exercise::countValid(const Matrix& m) {
    size_t cnt = 0;
    for (size_t i = 0; i < m.getSize(); ++i) {
        if (hasEvenFirstAndLast(m[i])) ++cnt;
    }
    return cnt;
}

void Task2Exercise::Task1() {}

void Task2Exercise::Task2() {
    size_t n = countValid(matrix);
    if (n == 0) {
        result = Matrix(0);
        return;
    }

    std::vector<int> filtered;
    for (size_t i = 0; i < matrix.getSize(); ++i) {
        if (hasEvenFirstAndLast(matrix[i])) {
            filtered.push_back(matrix[i]);
        }
    }

    result = Matrix(filtered);
}

void Task2Exercise::Task3() {}

const Matrix& Task2Exercise::getResult() const {
    return result;
}

}
