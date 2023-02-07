#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>

int main()
{
    int v[]{1, 2, 3};
#ifndef __clang__
    const auto result = std::ranges::next_permutation(v);

    std::ranges::for_each(std::cbegin(v), result.in, [](int e)
                          { std::cout << e << ' '; });

    std::cout << std::boolalpha << "\n"
                                   "result.found: "
              << result.found << '\n';
#endif
}