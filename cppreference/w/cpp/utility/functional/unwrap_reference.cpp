#include <cassert>
#include <iostream>
#include <functional>
#include <type_traits>
 
int main()
{
    static_assert(std::is_same_v<std::unwrap_reference_t<int>, int>);
    static_assert(std::is_same_v<std::unwrap_reference_t<const int>, const int>);
    static_assert(std::is_same_v<std::unwrap_reference_t<int&>, int&>);
    static_assert(std::is_same_v<std::unwrap_reference_t<int&&>, int&&>);
    static_assert(std::is_same_v<std::unwrap_reference_t<int*>, int*>);
 
    {
        using T = std::reference_wrapper<int>;
        using X = std::unwrap_reference_t<T>;
        static_assert(std::is_same_v<X, int&>);
    }
    {
        using T = std::reference_wrapper<int&>;
        using X = std::unwrap_reference_t<T>;
        static_assert(std::is_same_v<X, int&>);
    }
 
    static_assert(std::is_same_v<std::unwrap_ref_decay_t<int>, int>);
    static_assert(std::is_same_v<std::unwrap_ref_decay_t<const int>, int>);
    static_assert(std::is_same_v<std::unwrap_ref_decay_t<const int&>, int>);
 
    {
        using T = std::reference_wrapper<int&&>;
        using X = std::unwrap_ref_decay_t<T>;
        static_assert(std::is_same_v<X, int&>);
    }
 
    {
        auto reset = []<typename T>(T&& z) {
    //      x = 0; // Error: does not work if T is reference_wrapper<>
            // converts T&& into T& for ordinary types
            // converts T&& into U& for reference_wrapper<U>
            decltype(auto) r = std::unwrap_reference_t<T>(z);
            std::cout << "r: " << r << '\n';
            r = 0; // OK, r has reference type
        };
 
        int x = 1;
        reset(x);
        assert(x == 0);
 
        int y = 2;
        reset(std::ref(y));
        assert(y == 0);
    }
}