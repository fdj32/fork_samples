#include <algorithm>
#include <vector>
#include <iostream>
 
int main()
{
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
#ifndef __clang__
    namespace ranges = std::ranges;
    ranges::fill(v.begin(), v.end(), -1);
 
    for (auto elem : v)
        std::cout << elem << ' ';
    std::cout << "\n";
 
    ranges::fill(v, 10);
#endif
    for (auto elem : v)
        std::cout << elem << ' ';
    std::cout << "\n";
}