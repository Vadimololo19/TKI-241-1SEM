#pragma once
#include "Matrix.h"

namespace miit::algebra {

class Exercise {
protected:
    Matrix<int> matrix;

public:
    explicit Exercise(Matrix<int> mat);
    virtual ~Exercise() = default;

    virtual void Task1() = 0;
    virtual void Task2() = 0;
    virtual void Task3() = 0;

    const Matrix<int>& getMatrix() const;
};

}
