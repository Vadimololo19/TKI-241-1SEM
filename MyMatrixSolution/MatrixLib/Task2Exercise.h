#pragma once
#include "Exercise.h"

namespace miit::algebra {

class Task2Exercise : public Exercise {
    Matrix<int> result;

    static bool hasEvenFirstAndLast(int value);
    static size_t countValid(const Matrix<int>& m);

public:
    explicit Task2Exercise(Matrix<int> mat);

    void Task2();

    const Matrix<int>& getResult() const;
};

}
