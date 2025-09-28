#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include <sstream>
#include <gtest/gtest.h>

using namespace miit::algebra;

TEST(GeneratorTest, RandomGeneratorInRange) {
    RandomGenerator gen(5, 10);
    for (int i = 0; i < 100; ++i) {
        int val = gen.generate();
        EXPECT_GE(val, 5);
        EXPECT_LE(val, 10);
    }
}

TEST(GeneratorTest, IStreamGenerator) {
    std::istringstream iss("42 7 100");
    IStreamGenerator gen(iss);
    EXPECT_EQ(gen.generate(), 42);
    EXPECT_EQ(gen.generate(), 7);
    EXPECT_EQ(gen.generate(), 100);
}
