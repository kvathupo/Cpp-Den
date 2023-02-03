#include <gtest/gtest.h>
#include <cmath>

#include "pow.hpp"

TEST(PowTest, IntBaseIntExp) {
    constexpr double res1 = CompileTime::pow<10, 2, 10>();
    constexpr double res2 = CompileTime::pow<10, 4, 10>();
    constexpr double res3 = CompileTime::pow<10, 5, 10>();
    constexpr double res4 = CompileTime::pow<5, 2, 5>();
    constexpr double res5 = CompileTime::pow<6, 4, 6>();
    constexpr double res6 = CompileTime::pow<9, 5, 9>();

    EXPECT_NEAR(res1, std::pow(10, 2), 1 / 10000.0);
    EXPECT_NEAR(res2, std::pow(10, 4), 1 / 10000.0);
    EXPECT_NEAR(res3, std::pow(10, 5), 1 / 10000.0);
    EXPECT_NEAR(res4, std::pow(5, 2), 1 / 10000.0);
    EXPECT_NEAR(res5, std::pow(6, 4), 1 / 10000.0);
    EXPECT_NEAR(res6, std::pow(9, 5), 1 / 10000.0);
}

/**
 *
 * @TODO:
 *      - Integer multiplication overflows in std::ratio -> use a constexpr bigint library like ctbignum
 *
TEST(PowTest, FracBaseIntExp) {
    constexpr double res1 = CompileTime::pow<std::ratio<1, 2>, 2>();
    constexpr double res2 = CompileTime::pow<std::ratio<1, 2>, 4>();
    constexpr double res3 = CompileTime::pow<std::ratio<1, 2>, 5>();
    constexpr double res4 = CompileTime::pow<std::ratio<5, 6>, 2>();
    constexpr double res5 = CompileTime::pow<std::ratio<7, 44>, 4>();
    constexpr double res6 = CompileTime::pow<std::ratio<16, 7>, 5>();

    EXPECT_NEAR(res2, std::pow(0.5, 4), 1 / 10000.0);
    EXPECT_NEAR(res3, std::pow(0.5, 5), 1 / 10000.0);
    EXPECT_NEAR(res4, std::pow(5/6.0, 2), 1 / 10000.0);
    EXPECT_NEAR(res5, std::pow(7/44.0, 4), 1 / 10000.0);
    EXPECT_NEAR(res6, std::pow(16/7.0, 5), 1 / 10000.0);

    EXPECT_NEAR(res1, std::pow(0.5, 2), 1 / 10000.0);
}
*/
