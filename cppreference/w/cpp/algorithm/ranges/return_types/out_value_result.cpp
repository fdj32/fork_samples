#include <algorithm>
#include <array>
#include <cassert>
#include <ranges>
#include <numeric>
 
int main()
{
    std::array<int, 4> a;
    constexpr std::array expected{2,3,4,5};
/*
    const auto result = std::ranges::iota(a, 2);
    assert(std::ranges::distance(a.cbegin(), result.out) == 4);
    assert(result.value == 6);
    assert(a == expected);
*/
}