#include "Task1Exercise.h"
#include "Task2Exercise.h"
#include "Task3Exercise.h"
#include <gtest/gtest.h>

using namespace miit::algebra;

TEST(TaskTest, Task1_MinPositiveToZero) {
    Matrix<int> m({3, -1, 2, 5});
    Task1Exercise ex(std::move(m));
    ex.Task1();
    auto r = ex.getMatrix();
    EXPECT_EQ(r[2], 0);
}

TEST(TaskTest, Task2_FilterEvenDigits) {
    Matrix<int> m({24, 13, 86});
    Task2Exercise ex(std::move(m));
    ex.Task2();
    auto& r = ex.getResult();
    EXPECT_EQ(r.getSize(), 2);
    EXPECT_EQ(r[0], 24); EXPECT_EQ(r[1], 86);
}

TEST(TaskTest, Task3_ModifyByIndex) {
    Matrix<int> m({1,2,3,4});
    Task3Exercise ex(std::move(m));
    ex.Task3();
    auto r = ex.getMatrix();
    EXPECT_EQ(r[0], 0);     // 1-1
    EXPECT_EQ(r[1], 1);     // 2-1
    EXPECT_EQ(r[2], -9);    // -3²
}
