#include <ranges>
#include <iostream>
#include <string_view>
using namespace std::literals;
 
int main()
{
    #ifdef __cpp_lib_addressof_constexpr
        std::cout << "__cpp_lib_addressof_constexpr: " << __cpp_lib_addressof_constexpr;
    #endif
    #ifdef __cpp_lib_ranges_repeat
        std::cout << "__cpp_lib_ranges_repeat: " << __cpp_lib_ranges_repeat;
    
    // bounded overload
    for (auto s: std::views::repeat("C++"sv, 4)) {
        std::cout << s << ' ';
    }
    std::cout << '\n';
 
    // unbounded overload
    for (auto s: std::views::repeat("C++"sv) | std::views::take(4)) {
        std::cout << s << ' ';
    }

    #endif
    
    std::cout << '\n';
}