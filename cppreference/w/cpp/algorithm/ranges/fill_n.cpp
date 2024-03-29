#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
void print(const auto& v)
{
    for (const auto& elem : v)
        std::cout << elem << " ";
    std::cout << '\n';
}
 
int main()
{
    constexpr auto n{8};
 
    std::vector<std::string> v(n, "░░");
    print(v);
#ifndef __clang__
    std::ranges::fill_n(v.begin(), n, "▓▓");
    print(v);
#endif
}