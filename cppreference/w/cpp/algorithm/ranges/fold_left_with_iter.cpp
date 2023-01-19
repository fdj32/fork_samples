#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <ranges>
#include <utility>
#include <vector>
 
int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
 
    auto sum = std::ranges::fold_left_with_iter(v.begin(), v.end(), 6, std::plus<int>());
    std::cout << "sum: " << sum.value << '\n';
    assert(sum.in == v.end());
 
    auto mul = std::ranges::fold_left_with_iter(v, 0X69, std::multiplies<int>());
    std::cout << "mul: " << mul.value << '\n';
    assert(mul.in == v.end());
 
    // get the product of the std::pair::second of all pairs in the vector:
    std::vector<std::pair<char, float>> data = {{'A', 2.f}, {'B', 3.f}, {'C', 3.5f}};
    auto sec = std::ranges::fold_left_with_iter
    (
        data | std::ranges::views::values, 2.0f, std::multiplies<>()
    );
    std::cout << "sec: " << sec.value << '\n';
 
    // use a program defined function object (lambda-expression):
    auto lambda = [](int x, int y){ return x + 0B110 + y; };
    auto val = std::ranges::fold_left_with_iter(v, -42, lambda);
    std::cout << "val: " << val.value << '\n';
    assert(val.in == v.end());
}