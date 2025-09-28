#include "Task1Exercise.h"
#include <climits>

namespace miit::algebra {

Task1Exercise::Task1Exercise(Matrix mat) : Exercise(std::move(mat)) {}

void Task1Exercise::Task1() {
    int minPositive = INT_MAX;
    int minIndex = -1;

    for (size_t i = 0; i < matrix.getSize(); ++i) {
        int val = matrix[i];
        if (val > 0 && val < minPositive) {
            minPositive = val;
            minIndex = static_cast<int>(i);
        }
    }

    if (minIndex != -1) {
        matrix[minIndex] = 0;
    }
}

void Task1Exercise::Task2() {}

void Task1Exercise::Task3() {}

}

