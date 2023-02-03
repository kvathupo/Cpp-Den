#pragma once


#include <iostream>
#include <ratio>

#include "compute_utils.hpp"


namespace CompileTime {

/**
 *
 * @TODO:
 *      - Integer multiplication overflows in std::ratio -> use a constexpr bigint library like ctbignum
 *
 */
/*
template<Ratio base, unsigned int iexp, Ratio orig = base>
consteval double pow() {
   if constexpr (iexp == 0) {
        return base::num / static_cast<double>(base::den);
    } else if (std::ratio_equal<orig, base>::value) {
        return pow<std::ratio_multiply<base, base>, iexp - 2, orig>();
    } else {
        return pow<std::ratio_multiply<base, orig>, iexp - 1, orig>();
    }
};
*/

template<int base, int iexp, int orig>
consteval double pow() {
   if constexpr (iexp == 1)
        return base;
    else
        return pow<base * orig, iexp - 1, orig>();
};

}       // end namespace `CompileTime`
