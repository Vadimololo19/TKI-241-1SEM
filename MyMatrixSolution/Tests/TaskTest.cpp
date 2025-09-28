#include "Task1Exercise.h"
#include "Task2Exercise.h"
#include "Task3Exercise.h"
#include <gtest/gtest.h>

using namespace miit::algebra;

TEST(TaskTest, Task1_MinPositiveToZero) {
    Matrix m({3, -1, 2, 5});
    Task1Exercise ex(std::move(m));
    ex.Task1();
    auto result = ex.getMatrix();
    EXPECT_EQ(result[0], 3);
    EXPECT_EQ(result[1], -1);
    EXPECT_EQ(result[2], 0);  
    EXPECT_EQ(result[3], 5);
}

TEST(TaskTest, Task1_NoPositive) {
    Matrix m({-1, -2, -3});
    Task1Exercise ex(std::move(m));
    ex.Task1();
    auto result = ex.getMatrix();
    EXPECT_EQ(result[0], -1);
    EXPECT_EQ(result[1], -2);
    EXPECT_EQ(result[2], -3);
}

TEST(TaskTest, Task2_FilterEvenFirstLastDigit) {
    Matrix m({24, 13, 86, 77, 42}); 
    Task2Exercise ex(std::move(m));
    ex.Task2();
    auto& result = ex.getResult();
    EXPECT_EQ(result.getSize(), 3);
    EXPECT_EQ(result[0], 24);
    EXPECT_EQ(result[1], 86);
    EXPECT_EQ(result[2], 42);
}

TEST(TaskTest, Task2_NoValidElements) {
    Matrix m({13, 57, 91});
    Task2Exercise ex(std::move(m));
    ex.Task2();
    auto& result = ex.getResult();
    EXPECT_EQ(result.getSize(), 0);
}

TEST(TaskTest, Task3_ModifyByIndex) {
    Matrix m({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13});
    Task3Exercise ex(std::move(m));
    ex.Task3();
    auto result = ex.getMatrix();

    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);

    EXPECT_EQ(result[2], -9);
    EXPECT_EQ(result[3], -16);
    EXPECT_EQ(result[11], -144);

    EXPECT_EQ(result[12], 12);
}
