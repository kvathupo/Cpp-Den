#pragma once

#include <concepts>
#include <type_traits>
#include <ranges>


namespace Sorts {

namespace {


template<typename T>
concept MergeableArray = std::is_array<T>::value;

template<typename T>
concept MergeableContainer = 
    (std::totally_ordered<T> &&
    std::copyable<T> &&
    requires(T obj) {
        std::ranges::begin(obj);
        std::ranges::cbegin(obj);
        std::ranges::end(obj);
        std::ranges::cend(obj);
    }) || MergeableArray<T>;


/*
 *  Merge subarrays of `from_arr` defined by the ranges in [left, mid)
 *  and [mid, right) into `to_arr` in sorted order.
 *
 *  @param to_arr: Container to hold sorted elements
 *  @param from_arr: Container with sorted subarrays
 *  @param left: start of first subarray
 *  @param mid: start of second subarray
 *  @param right: end of second subarray, non-exclusive
 *
 *  @requires:
 *      - The subarrays to be merged are themselves sorted
 *
 */
template<MergeableContainer T>
inline void merge(T& to_arr, T& from_arr, std::size_t left, std::size_t mid, std::size_t right) {
    std::size_t i {left}, j {mid};

    for (auto itr = std::ranges::begin(to_arr) + left; itr != std::ranges::begin(to_arr) + right; ++itr) {
        if (i < mid && 
            (j >= right ||
            *(std::ranges::cbegin(from_arr) + i) < *(std::ranges::cbegin(from_arr) + j))) {
            *itr = *(std::ranges::cbegin(from_arr) + i);
            ++i;
        } else {
            *itr = *(std::ranges::cbegin(from_arr) + j);
            ++j;
        }
    }
};


/*
 *  Recursively split container in [start, end) down the middle.
 *
 *  @param to_arr: Container to hold sorted contents
 *  @param from_arr: Container to be sorted
 *  @param start: Start of container inclusive
 *  @param end: End of container exclusive
 *
 */
template<MergeableContainer T>
inline void split(T& to_arr, T& from_arr, std::size_t start, std::size_t end) {
    if (end - start > 1) {
        std::size_t mid = (start + end) / 2;
        split(from_arr, to_arr, start, mid);
        split(from_arr, to_arr, mid, end);
        merge(to_arr, from_arr, start, mid, end);
    }
};


}       // end anonymous namespace


/*
 *  Sorts via merge-sort.
 *
 *  @param arr: input array
 */
template<MergeableArray T>
inline void merge_sort(T& arr) {
    T arr_copy;
    std::copy(std::ranges::cbegin(arr), std::ranges::cend(arr), std::ranges::begin(arr_copy));
    split(arr, arr_copy, 0, std::size(arr));
};

/*
 *  Sorts via merge-sort.
 *
 *  @param arr: input container whose elements are totally ordered.
 */
template<MergeableContainer T>
inline void merge_sort(T& arr) {
    T arr_copy {arr};
    std::copy(std::ranges::cbegin(arr), std::ranges::cend(arr), std::ranges::begin(arr_copy));
    split(arr, arr_copy, 0, std::size(arr));
};


}       // end namespace `Sorts`
