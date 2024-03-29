#include <algorithm>
#include <array>
#include <iostream>
#include <random>
 
void print(const auto& a) {
    for (const auto e : a) { std::cout << e << ' '; }
    std::cout << "\n";
}
 
int main()
{
    std::array a{'A', 'B', 'C', 'D', 'E', 'F'};
    print(a);
 
    std::random_device rd;
    std::mt19937 gen{rd()};
#ifndef __clang__
    for (int i{}; i != 3; ++i) {
        std::ranges::shuffle(a, gen);
        print(a);
    }
#endif
}