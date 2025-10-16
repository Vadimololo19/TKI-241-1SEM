#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include <sstream>
#include <gtest/gtest.h>

using namespace miit::algebra;

TEST(GeneratorTest, RandomInRange) {
    RandomGenerator gen(5, 10);
    for (int i = 0; i < 100; ++i) {
        int v = gen.generate();
        EXPECT_GE(v, 5); EXPECT_LE(v, 10);
    }
}

TEST(GeneratorTest, ReadFromStream) {
    std::istringstream iss("42 7");
    IStreamGenerator gen(iss);
    EXPECT_EQ(gen.generate(), 42);
    EXPECT_EQ(gen.generate(), 7);
}
