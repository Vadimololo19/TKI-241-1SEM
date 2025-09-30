#pragma once
#include "Exercise.h"
#include <climits>

namespace miit::algebra {

class Task1Exercise : public Exercise<int> {
public:
    explicit Task1Exercise(Matrix<int> mat);

    void Task1() override;
    void Task2() override;
    void Task3() override;
};

}
