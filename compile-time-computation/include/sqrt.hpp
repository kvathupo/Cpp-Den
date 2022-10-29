#pragma once


#include <iostream>
#include <ratio>

#include "compute_utils.hpp"


/*
 *   - @TODO: `std::abs` is apparently `constexpr` in c++23 ?
 *  Might be able to replace some of the metaprogramming.
 *
 */


namespace CompileTime {

/*
 *  Calculates the square-root of `target` using Newton's method.
 *  All parameters are specialization of `std::ratio`, and type-enforced.
 *
 *  @param square_root: Our initial guess in Newton's method
 *  @param target: The value that we want to square root.
 *  @param epsilon: Our stopping tolerance. Recursion will continue
 *  until the difference between the square of our running estimate
 *  and `target` is strictly less than `epsilon`.
 */
template<Ratio square_root, Ratio target, Ratio epsilon>
consteval double sqrt() {
    using diff = std::ratio_subtract<target, std::ratio_multiply<square_root, square_root>>;

    // is the difference negative?
    // if so, multiply by -1
    if constexpr (std::ratio_less<diff, std::ratio<0, 1>>::value) {
        using positive_diff = std::ratio_multiply<diff, std::ratio<-1, 1>>;

        // return if within error bounds, else continue
        if constexpr (std::ratio_greater_equal<square_root, std::ratio<0, 1>>::value && std::ratio_less<positive_diff, epsilon>::value) {
            return square_root::num / static_cast<double>(square_root::den);
        } else {
            using func_val = std::ratio_subtract<std::ratio_multiply<square_root, square_root>, target>;
            using deriv_val = std::ratio_multiply<square_root, std::ratio<2, 1>>;
            using next_iter = std::ratio_subtract<square_root, std::ratio_divide<func_val, deriv_val>>;
            return sqrt<next_iter, target, epsilon>();
        }
    } else {
        // return if within error bounds, else continue
        if constexpr (std::ratio_greater_equal<square_root, std::ratio<0, 1>>::value && std::ratio_less<diff, epsilon>::value)
            return square_root::num / static_cast<double>(square_root::den);
        else {
            using func_val = std::ratio_subtract<std::ratio_multiply<square_root, square_root>, target>;
            using deriv_val = std::ratio_multiply<square_root, std::ratio<2, 1>>;
            using next_iter = std::ratio_subtract<square_root, std::ratio_divide<func_val, deriv_val>>;
            return sqrt<next_iter, target, epsilon>();
        }
    }
};

}       // end namespace `CompileTime`
