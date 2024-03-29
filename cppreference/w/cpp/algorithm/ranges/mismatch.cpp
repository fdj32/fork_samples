#include <algorithm>
#include <cstddef>
#include <iostream>
#include <ranges>
#include <string_view>

#ifndef __clang__
constexpr std::string_view mirror_ends(const std::string_view in)
{
    const auto end = std::ranges::mismatch(in, in | std::views::reverse).in1;
    const std::size_t length = std::ranges::distance(in.begin(), end);
    return { in.cbegin(), length };
}
#endif

int main()
{
#ifndef __clang__
    std::cout << mirror_ends("abXYZba") << '\n'
              << mirror_ends("abca") << '\n'
              << mirror_ends("ABBA") << '\n'
              << mirror_ends("level") << '\n';
 
    using namespace std::literals::string_view_literals;
 
    static_assert("123"sv == mirror_ends("123!@#321"));
    static_assert("radar"sv == mirror_ends("radar"));
#endif
}