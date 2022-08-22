#include <concepts>
#include <iterator>
#include <type_traits>


// headers I don't need
#include <vector>
#include <iostream>


template<typename T>
concept MergeableContainer = 
    (std::totally_ordered<T> &&
    std::copyable<T> &&
    requires(T obj) {
        std::begin(obj);
        std::cbegin(obj);
        std::end(obj);
        std::cend(obj);
    }) || std::is_array<T>::value;

template<MergeableContainer T>
void foo(T& v) {
    std::cout << "compiled!" << std::endl;
};

template<typename T>
void bar(T& arr) {
    std::cout << "arr = {";
    for (auto itr = std::begin(arr); itr != std::end(arr); ++itr) {
        if (itr + 1 == std::end(arr)) 
            std::cout << *itr << "}" << std::endl;
        else
            std::cout << *itr << ", ";
    }
};

int main() {
    std::vector<int> v {1, 2, 3};
    foo(v);
    int arr[5] = {1, 2, 3, 4, 5};

    foo(arr);

    return 0;
};
