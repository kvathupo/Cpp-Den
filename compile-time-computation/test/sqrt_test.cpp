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

TEST(SqrtTest, FractionalArg) {
    float squarable1 = 200.0 / 324;
    float squarable2 = 809.0 / 82;
    constexpr double arg1 = CompileTime::sqrt<std::ratio<39, 50>, std::ratio<200, 324>, std::ratio<1, 10000>>();
    constexpr double arg2 = CompileTime::sqrt<std::ratio<39, 50>, std::ratio<200, 324>, std::ratio<1, 1000>>();
    constexpr double arg3 = CompileTime::sqrt<std::ratio<39, 50>, std::ratio<200, 324>, std::ratio<1, 100>>();

    EXPECT_NEAR(arg1, std::sqrt(squarable1), 1 / 10000.0);
    EXPECT_NEAR(arg2, std::sqrt(squarable1), 1 / 1000.0);
    EXPECT_NEAR(arg3, std::sqrt(squarable1), 1 / 100.0);

/**
 *
 * @TODO:
 *      - Integer multiplication overflows in std::ratio -> use a constexpr bigint library like ctbignum
 *
 */
/*
    constexpr double arg4 = CompileTime::sqrt<std::ratio<7, 2>, std::ratio<809, 82>, std::ratio<1, 10000>>();
    constexpr double arg5 = CompileTime::sqrt<std::ratio<7, 2>, std::ratio<809, 82>, std::ratio<1, 1000>>();
    constexpr double arg6 = CompileTime::sqrt<std::ratio<7, 2>, std::ratio<809, 82>, std::ratio<1, 100>>();

    EXPECT_NEAR(arg4, std::sqrt(squarable2), 1 / 10000.0);
    EXPECT_NEAR(arg5, std::sqrt(squarable2), 1 / 1000.0);
    EXPECT_NEAR(arg6, std::sqrt(squarable2), 1 / 100.0);
*/
}
