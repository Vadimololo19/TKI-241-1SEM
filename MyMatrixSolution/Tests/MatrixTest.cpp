#include "Matrix.h"
#include "RandomGenerator.h"
#include <gtest/gtest.h>

using namespace miit::algebra;

TEST(MatrixTest, CreateWithSize) {
    Matrix<int> m(5);
    EXPECT_EQ(m.getSize(), 5);
}

TEST(MatrixTest, AccessElements) {
    Matrix<int> m(3);
    m[0] = 10; m[1] = 20; m[2] = 30;
    EXPECT_EQ(m[0], 10);
    EXPECT_EQ(m[1], 20);
    EXPECT_EQ(m[2], 30);
}

TEST(MatrixTest, FillWithRandom) {
    Matrix<int> m(5);
    RandomGenerator<int> gen(1, 10);
    m.fill(5, gen);
    for (size_t i = 0; i < m.getSize(); ++i) {
        EXPECT_GE(m[i], 1);
        EXPECT_LE(m[i], 10);
    }
}
