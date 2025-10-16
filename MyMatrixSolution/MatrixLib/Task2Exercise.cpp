#include "Task2Exercise.h"
#include <cmath>

namespace miit::algebra {

Task2Exercise::Task2Exercise(Matrix<int> mat) : Exercise(std::move(mat)), result(0) {}

bool Task2Exercise::hasEvenFirstAndLast(int value) {
    int n = std::abs(value);
    if (n == 0) return false;
    int last = n % 10;
    int first = n;
    while (first >= 10) first /= 10;
    return (first % 2 == 0) && (last % 2 == 0);
}

size_t Task2Exercise::countValid(const Matrix<int>& m) {
    size_t cnt = 0;
    for (size_t i = 0; i < m.getSize(); ++i) {
        if (hasEvenFirstAndLast(m[i])) ++cnt;
    }
    return cnt;
}

void Task2Exercise::Task2() {
    size_t n = countValid(matrix);
    if (n == 0) {
        result = Matrix<int>(0);
        return;
    }

    std::unique_ptr<int[]> temp = std::make_unique<int[]>(n);
    size_t idx = 0;
    for (size_t i = 0; i < matrix.getSize(); ++i) {
        if (hasEvenFirstAndLast(matrix[i])) {
            temp[idx++] = matrix[i];
        }
    }

    result = Matrix<int>(temp.get(), n);
}

const Matrix<int>& Task2Exercise::getResult() const {
    return result;
}

}
