#include <ranges>
#include <iostream>
#include <algorithm>
 
int main()
{
    #ifdef __cpp_lib_addressof_constexpr
        std::cout << "__cpp_lib_addressof_constexpr: " << __cpp_lib_addressof_constexpr;
    #endif
    #ifdef __cpp_lib_ranges_repeat
        std::cout << "__cpp_lib_ranges_repeat: " << __cpp_lib_ranges_repeat;

    for (int i : std::ranges::iota_view{1, 10})
        std::cout << i << ' ';
    std::cout << '\n';
 
    for (int i : std::views::iota(1, 10))
        std::cout << i << ' ';
    std::cout << '\n';
 
    struct Bound
    {
        int bound;
        bool operator==(int x) const { return x == bound; }
    };
    for (int i : std::views::iota(1, Bound{10}))
        std::cout << i << ' ';
    std::cout << '\n';
 
    for (int i : std::views::iota(1) | std::views::take(9))
        std::cout << i << ' ';
    std::cout << '\n';
 
    std::ranges::for_each(std::views::iota(1, 10), [](int i) {
        std::cout << i << ' ';
    });

    #endif

    std::cout << '\n';
}