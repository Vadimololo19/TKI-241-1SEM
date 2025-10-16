#pragma once
#include "Matrix.h"

namespace miit::algebra {

class Exercise {
protected:
    Matrix<int> matrix;

public:
    explicit Exercise(Matrix<int> mat);
    virtual ~Exercise() = default;

    const Matrix<int>& getMatrix() const;
};

}
