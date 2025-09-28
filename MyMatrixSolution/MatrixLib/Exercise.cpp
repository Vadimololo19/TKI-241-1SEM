#include "Exercise.h"

namespace miit::algebra {

Exercise::Exercise(Matrix mat) : matrix(std::move(mat)) {}

const Matrix& Exercise::getMatrix() const {
    return matrix;
}

}
