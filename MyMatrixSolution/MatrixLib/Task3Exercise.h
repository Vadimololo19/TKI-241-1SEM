#pragma once
#include "Exercise.h"
#include <cmath>

namespace miit::algebra {

class Task3Exercise : public Exercise<int> {
public:
    explicit Task3Exercise(Matrix<int> mat);

    void Task1() override;
    void Task2() override;
    void Task3() override;
};

} 
