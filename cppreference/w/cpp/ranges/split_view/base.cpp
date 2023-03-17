
 #include <iostream>
#include <iomanip>
#include <ranges>
#include <string_view>

int main()
{
    constexpr std::string_view keywords{ "this throw true try typedef typeid" };
    std::ranges::split_view split_view{ keywords, ' ' };
    std::cout << "base() = " << std::quoted( split_view.base() ) << "\n"
                 "substrings: ";
    for (auto split: split_view)
        std::cout << std::quoted( std::string_view{ split } ) << ' ';
}
