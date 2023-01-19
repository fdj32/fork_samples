#include <algorithm>
#include <functional>
#include <iostream>
#include <ranges>
#include <utility>
#include <vector>
 
int main()
{
    auto v = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<std::string> vs{"A", "B", "C", "D"};
 
    auto r1 = std::ranges::fold_right_last(v.begin(), v.end(), std::plus<>()); // (1)
    std::cout << "*r1: " << *r1 << '\n';
 
    auto r2 = std::ranges::fold_right_last(vs, std::plus<>()); // (2)
    std::cout << "*r2: " << *r2 << '\n';
 
    // Use a program defined function object (lambda-expression):
    auto r3 = std::ranges::fold_right_last(v, [](int x, int y) { return x + y + 99; });
    std::cout << "*r3: " << *r3 << '\n';
 
    // Get the product of the std::pair::second of all pairs in the vector:
    std::vector<std::pair<char, float>> data = {{'A', 3.f}, {'B', 3.5f}, {'C', 4.f}};
    auto r4 = std::ranges::fold_right_last
    (
        data | std::ranges::views::values, std::multiplies<>()
    );
    std::cout << "*r4: " << *r4 << '\n';
}