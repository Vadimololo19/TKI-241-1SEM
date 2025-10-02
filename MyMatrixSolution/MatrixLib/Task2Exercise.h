#pragma once
#include "Exercise.h"

namespace miit::algebra {

class Task2Exercise : public Exercise {
    Matrix<int> result;

    static bool hasEvenFirstAndLast(int value);
    static size_t countValid(const Matrix<int>& m);

public:
    explicit Task2Exercise(Matrix<int> mat);

    void Task1() override;
    void Task2() override;
    void Task3() override;

    const Matrix<int>& getResult() const;
};

}
