#include <algorithm>
#include <functional>
#include <iostream>
#include <ranges>
#include <string>
#include <utility>
#include <vector>
using namespace std::literals;
 
int main()
{
    auto v = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<std::string> vs{"A", "B", "C", "D"};
 
    auto r1 = std::ranges::fold_right(v.begin(), v.end(), 6, std::plus<>()); // (1)
    std::cout << "r1: " << r1 << '\n';
 
    auto r2 = std::ranges::fold_right(vs, "!"s, std::plus<>()); // (2)
    std::cout << "r2: " << r2 << '\n';
 
    // Use a program defined function object (lambda-expression):
    std::string r3 = std::ranges::fold_right
    (
        v, "A", [](int x, std::string s) { return s + ':' + std::to_string(x); }
    );
    std::cout << "r3: " << r3 << '\n';
 
    // Get the product of the std::pair::second of all pairs in the vector:
    std::vector<std::pair<char, float>> data = {{'A', 2.f}, {'B', 3.f}, {'C', 3.5f}};
    float r4 = std::ranges::fold_right
    (
        data | std::ranges::views::values, 2.0f, std::multiplies<>()
    );
    std::cout << "r4: " << r4 << '\n';
}