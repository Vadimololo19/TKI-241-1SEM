#pragma once
#include "Exercise.h"

namespace miit::algebra {

class Task3Exercise : public Exercise {
public:
    explicit Task3Exercise(Matrix mat);

    void Task1() override;
    void Task2() override;
    void Task3() override;
};

}
