#pragma once
#include "Exercise.h"

namespace miit::algebra {

class Task2Exercise : public Exercise {
    Matrix result;

    static bool hasEvenFirstAndLast(int value);
    static size_t countValid(const Matrix& m);

public:
    explicit Task2Exercise(Matrix mat);

    void Task1() override;
    void Task2() override;
    void Task3() override;

    const Matrix& getResult() const;
};

}
