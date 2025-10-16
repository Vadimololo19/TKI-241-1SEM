#include "Task1Exercise.h"

namespace miit::algebra {

Task1Exercise::Task1Exercise(Matrix<int> mat) : Exercise(std::move(mat)) {}

void Task1Exercise::Task1() {
    int minPositive = 0;
    bool found = false;
    for (size_t i = 0; i < matrix.getSize(); ++i) {
        int val = matrix[i];
        if (val > 0) {
            if (!found) {
                minPositive = val;
                found = true;
            } else if (val < minPositive) {
                minPositive = val;
            }
        }
    }

    if (found) {
        for (size_t i = 0; i < matrix.getSize(); ++i) {
            if (matrix[i] == minPositive) {
                matrix[i] = 0;
                break;
            }
        }
    }
}

}
