#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <ranges>
 
int main()
{
    constexpr char in[] = "transform" "\n";
    std::array<char, sizeof(in)> out;
#ifndef __clang__
    const auto result = std::ranges::transform(in, out.begin(),
        [](char c) { return std::toupper(c); });
 
    auto print = [](char c) { std::cout << c; };
    std::ranges::for_each(std::cbegin(in), result.in, print);
    std::ranges::for_each(out.cbegin(), result.out, print);
#endif
}