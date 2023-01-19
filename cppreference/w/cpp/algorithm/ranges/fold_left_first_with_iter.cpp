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
 
    auto sum = std::ranges::fold_left_first_with_iter
    (
        v.begin(), v.end(), std::plus<int>()
    );
    std::cout << "sum: " << sum.value.value() << '\n';
    assert(sum.in == v.end());
 
    auto mul = std::ranges::fold_left_first_with_iter(v, std::multiplies<int>());
    std::cout << "mul: " << mul.value.value() << '\n';
    assert(mul.in == v.end());
 
    // get the product of the std::pair::second of all pairs in the vector:
    std::vector<std::pair<char, float>> data = {{'A', 2.f}, {'B', 3.f}, {'C', 7.f}};
    auto sec = std::ranges::fold_left_first_with_iter
    (
        data | std::ranges::views::values, std::multiplies<>()
    );
    std::cout << "sec: " << sec.value.value() << '\n';
 
    // use a program defined function object (lambda-expression):
    auto lambda = [](int x, int y){ return x + y + 2; };
    auto val = std::ranges::fold_left_first_with_iter(v, lambda);
    std::cout << "val: " << val.value.value() << '\n';
    assert(val.in == v.end());
}