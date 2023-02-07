#include <algorithm>
#include <functional>
#include <iostream>
#include <ranges>
#include <string>
#include <utility>
#include <vector>
 
int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
#ifndef __clang__
    int sum = std::ranges::fold_left(v.begin(), v.end(), 0, std::plus<int>()); // (1)
    std::cout << "sum: " << sum << '\n';
 
    int mul = std::ranges::fold_left(v, 1, std::multiplies<int>()); // (2)
    std::cout << "mul: " << mul << '\n';
 
    // get the product of the std::pair::second of all pairs in the vector:
    std::vector<std::pair<char, float>> data = {{'A', 2.f}, {'B', 3.f}, {'C', 3.5f}};
    float sec = std::ranges::fold_left
    (
        data | std::ranges::views::values, 2.0f, std::multiplies<>()
    );
    std::cout << "sec: " << sec << '\n';
 
    // use a program defined function object (lambda-expression):
    std::string str = std::ranges::fold_left
    (
        v, "A", [](std::string s, int x) { return s + ':' + std::to_string(x); }
    );
    std::cout << "str: " << str << '\n';
#endif
}