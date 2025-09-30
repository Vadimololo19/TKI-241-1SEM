#include "Task1Exercise.h"
#include "Task2Exercise.h"
#include "Task3Exercise.h"
#include <gtest/gtest.h>

using namespace miit::algebra;

TEST(TaskTest, Task1_MinPositiveToZero) {
    Task1Exercise ex(Matrix<int>({3, -1, 2, 5}));
    ex.Task1();
    auto m = ex.getMatrix();
    EXPECT_EQ(m[2], 0);
}

TEST(TaskTest, Task2_FilterEvenDigits) {
    Task2Exercise ex(Matrix<int>({24, 13, 86, 77, 42}));
    ex.Task2();
    auto& r = ex.getResult();
    EXPECT_EQ(r.getSize(), 3);
    EXPECT_EQ(r[0], 24);
    EXPECT_EQ(r[1], 86);
    EXPECT_EQ(r[2], 42);
}

TEST(TaskTest, Task3_ModifyByIndex) {
    Matrix<int> m({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13});
    Task3Exercise ex(std::move(m));
    ex.Task3();
    auto r = ex.getMatrix();
    EXPECT_EQ(r[2], -9);
    EXPECT_EQ(r[12], 12);
}
