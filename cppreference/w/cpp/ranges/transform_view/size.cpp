#include <iostream>
#include <ranges>
#include <string>
#include <cctype>
 
int main()
{
    std::string s{"The length of this string is 42 characters"};

    #ifdef __cpp_lib_addressof_constexpr
        std::cout << "__cpp_lib_addressof_constexpr: " << __cpp_lib_addressof_constexpr;
    #endif
    #ifdef __cpp_lib_ranges_repeat
        std::cout << "__cpp_lib_ranges_repeat: " << __cpp_lib_ranges_repeat;

    auto tv = std::ranges::transform_view{s, [](char c) -> char {
        return std::toupper(c); }
    };
    for (auto x: tv) { std::cout << x; };
    std::cout << "\nsize = " << tv.size() << '\n';
    #endif
}