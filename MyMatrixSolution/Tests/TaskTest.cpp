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
    testing::internal::CaptureStdout();
    Matrix<int> m({24, 13, 86, 77, 42});
    Task2Exercise ex(std::move(m));
    ex.Task2();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("24"), std::string::npos);
    EXPECT_NE(output.find("86"), std::string::npos);
    EXPECT_NE(output.find("42"), std::string::npos);
    EXPECT_EQ(output.find("13"), std::string::npos);
    EXPECT_EQ(output.find("77"), std::string::npos);
    EXPECT_NE(output.find("Task2 result: [ "), std::string::npos);
}
TEST(TaskTest, Task3_ModifyByIndex) {
    Matrix<int> m({1,2,3,4});
    Task3Exercise ex(std::move(m));
    ex.Task3();
    auto r = ex.getMatrix();
    EXPECT_EQ(r[0], 0);    
    EXPECT_EQ(r[1], 1);     
    EXPECT_EQ(r[2], -9);    
}
