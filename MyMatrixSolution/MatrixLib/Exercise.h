#pragma once
#include "Matrix.h"

namespace miit::algebra {

template <typename T>
class Exercise {
protected:
    Matrix<T> matrix;
public:
    explicit Exercise(Matrix<T> mat);
    virtual ~Exercise() = default;

    virtual void Task1() = 0;
    virtual void Task2() = 0;
    virtual void Task3() = 0;

    const Matrix<T>& getMatrix() const;
};

template <typename T>
Exercise<T>::Exercise(Matrix<T> mat) : matrix(std::move(mat)) {}

template <typename T>
const Matrix<T>& Exercise<T>::getMatrix() const {
    return matrix;
}

} 
