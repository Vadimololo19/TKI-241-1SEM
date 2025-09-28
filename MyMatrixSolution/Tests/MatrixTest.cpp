#include "Matrix.h"
#include "RandomGenerator.h"
#include <sstream>
#include <vector>
#include <gtest/gtest.h>

using namespace miit::algebra;

TEST(MatrixTest, CreateWithSize) {
    Matrix m(5);
    EXPECT_EQ(m.getSize(), 5);
}

TEST(MatrixTest, AccessElements) {
    Matrix m(3);
    m[0] = 10;
    m[1] = 20;
    m[2] = 30;
    EXPECT_EQ(m[0], 10);
    EXPECT_EQ(m[1], 20);
    EXPECT_EQ(m[2], 30);
}

TEST(MatrixTest, FillWithRandom) {
    Matrix m(5);
    RandomGenerator gen(1, 10);
    m.fill(5, gen);
    for (size_t i = 0; i < m.getSize(); ++i) {
        EXPECT_GE(m[i], 1);
        EXPECT_LE(m[i], 10);
    }
}

TEST(MatrixTest, ToString) {
    Matrix m({1, 2, 3});
    std::ostringstream oss;
    oss << m;
    EXPECT_EQ(oss.str(), "[ 1 2 3 ]");
}
