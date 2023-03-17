
 #include <iostream>
#include <ranges>
#include <string>
#include <cctype>

int main()
{
    std::string s{"The length of this string is 42 characters"};
    auto tv = std::ranges::transform_view{s, [](char c) -> char {
        return std::toupper(c); }
    };
    for (auto x: tv) { std::cout << x; };
    std::cout << "\nsize = " << tv.size() << '\n';
}
