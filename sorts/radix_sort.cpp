#include <iostream>
#include <concepts>
#include <ranges>
#include <type_traits>
#include <vector>
#include <unordered_map>

template<typename T>
concept IntegralContainer = std::constructible_from<std::vector<T>> && 
    std::integral<typename T::value_type>;


inline namespace sorting {

/*
 *  Returns the number of digits in the member of an integral container with 
 *  the most decimal digits
 */
template<IntegralContainer T>
std::size_t get_digit_bound(const T& container) {
    for (const auto& ele : container) {
        // @TODO: bitshift equiv of greater than for the max
    }
};

template<IntegralContainer T>
void radix_sort(T container) {
    std::size_t max_digit = get_digit_bound(container);

    for (const auto& digit : std::views::iota(1, max_digit)) {
        // stable sort on digit
    }
};

}


int main() {
    std::vector<unsigned int> cnt {1, 2, 3, 4};
    radix_sort(cnt);

    return EXIT_SUCCESS;
}
