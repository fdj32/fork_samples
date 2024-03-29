#include <algorithm>
#include <iostream>
#include <ranges>
 
int main()
{
    constexpr static auto haystack = {1, 3, 4, 5, 9};
#ifndef __clang__
    static_assert(std::ranges::is_sorted(haystack));
 
    for (const int needle : std::views::iota(1)
                          | std::views::take(3))
    {
        std::cout << "Searching for " << needle << ": ";
        std::ranges::binary_search(haystack, needle)
            ? std::cout << "found " << needle << '\n'
            : std::cout << "no dice!\n";
    }
#endif
}