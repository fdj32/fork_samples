#include <algorithm>
#include <functional>
#include <iostream>
#include <ranges>
#include <utility>
#include <vector>
 
int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
#ifndef __clang__
    auto sum = std::ranges::fold_left_first(v.begin(), v.end(), std::plus<int>()); // (1)
    std::cout << "*sum: " << sum.value() << '\n';
 
    auto mul = std::ranges::fold_left_first(v, std::multiplies<int>()); // (2)
    std::cout << "*mul: " << mul.value() << '\n';
 
    // get the product of the std::pair::second of all pairs in the vector:
    std::vector<std::pair<char, float>> data = {{'A', 3.f}, {'B', 3.5f}, {'C', 4.f}};
    auto sec = std::ranges::fold_left_first
    (
        data | std::ranges::views::values, std::multiplies<>()
    );
    std::cout << "*sec: " << *sec << '\n';
 
    // use a program defined function object (lambda-expression):
    auto val = std::ranges::fold_left_first(v, [](int x, int y) { return x + y + 13; });
    std::cout << "*val: " << *val << '\n';
#endif
}