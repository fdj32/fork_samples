#include <algorithm>
#include <ranges>

int main()
{
#ifndef __clang__
    constexpr static auto v = {3, 1, 4, 1, 5, 9, 2};
    {
        constexpr auto result = std::ranges::minmax(v);
        static_assert(1 == result.min && 9 == result.max);
    }
    {
        constexpr auto result = std::ranges::minmax_element(v);
        static_assert(1 == *result.min && 9 == *result.max);
    }
#endif
}