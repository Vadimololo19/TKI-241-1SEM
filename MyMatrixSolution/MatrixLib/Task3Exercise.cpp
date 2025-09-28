#include "Task3Exercise.h"
#include <cmath>

namespace miit::algebra {

Task3Exercise::Task3Exercise(Matrix mat) : Exercise(std::move(mat)) {}

void Task3Exercise::Task1() {}

void Task3Exercise::Task2() {}

void Task3Exercise::Task3() {
    for (size_t i = 0; i < matrix.getSize(); ++i) {
        if (i >= 2 && i <= 11) {
            matrix[i] = -static_cast<int>(std::pow(matrix[i], 2));
        } else {
            matrix[i] = matrix[i] - 1;
        }
    }
}

}
