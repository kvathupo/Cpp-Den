#include <gtest/gtest.h>
#include <cmath>

#include "sqrt.hpp"

TEST(SqrtTest, IntegerArg) {
    constexpr double meaning_of_life = CompileTime::sqrt<std::ratio<6, 1>, std::ratio<42, 1>, std::ratio<1, 10000>>();
    constexpr double arg1 = CompileTime::sqrt<std::ratio<6, 1>, std::ratio<42, 1>, std::ratio<1, 1000>>();
    constexpr double arg2 = CompileTime::sqrt<std::ratio<6, 1>, std::ratio<42, 1>, std::ratio<1, 100>>();

    EXPECT_NEAR(meaning_of_life, std::sqrt(42), 1 / 10000.0);
    EXPECT_NEAR(arg1, std::sqrt(42), 1 / 1000.0);
    EXPECT_NEAR(arg2, std::sqrt(42), 1 / 100.0);
}
