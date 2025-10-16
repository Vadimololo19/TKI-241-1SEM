#include "Task1Exercise.h"

namespace miit::algebra {

Task1Exercise::Task1Exercise(Matrix<int> mat) : Exercise(std::move(mat)) {}

void Task1Exercise::Task1() {
    int minIndex = -1;

    for (size_t i = 0; i < matrix.getSize(); ++i) {
        if (matrix[i] > 0) {
            if (minIndex == -1) {
                minIndex = static_cast<int>(i);
            } else if (matrix[i] < matrix[static_cast<size_t>(minIndex)]) {
                minIndex = static_cast<int>(i);
            }
        }
    }

    if (minIndex != -1) {
        matrix[static_cast<size_t>(minIndex)] = 0;
    }
}
}
