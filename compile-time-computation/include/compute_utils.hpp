#pragma once
/*
 *  A collection of utilities common to this library.
 */
#include <concepts>
#include <type_traits>
#include <ratio>


namespace CompileTime {

/*
 *  @TODO: Replace with contents of P2098R1 if it gets accepted into c++23
 *      - Currently adapted from https://stackoverflow.com/questions/70130735/c-concept-to-check-for-derived-from-template-specialization
 */

template <typename T, template <long int, long int> class U>
struct is_specialization_of : std::false_type {};

template <long int... Args, template <long int, long int> class U>
struct is_specialization_of<U<Args...>, U> : std::true_type {};

template<typename T>
concept Ratio = is_specialization_of<T, std::ratio>::value;

}       // end namespace `CompileTime`
