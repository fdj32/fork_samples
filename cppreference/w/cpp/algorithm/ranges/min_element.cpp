#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
 
int main()
{
    std::vector<int> v{ 3, 1, -14, 1, 5, 9 };
#ifndef __clang__
    namespace ranges = std::ranges;
    auto result = ranges::min_element(v.begin(), v.end());
    std::cout << "min element at: " << ranges::distance(v.begin(), result) << '\n';
 
    auto abs_compare = [](int a, int b) { return (std::abs(a) < std::abs(b)); };
    result = ranges::min_element(v, abs_compare);
    std::cout << "min element (absolute) at: " << ranges::distance(v.begin(), result) << '\n';
#endif
}