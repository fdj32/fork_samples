#include <iostream>
#include <chrono>
 
int main()
{
    std::cout << std::boolalpha;
 
    auto ym {std::chrono::day(1)/7/2023};
 
    ym -= std::chrono::years {2};
    std::cout << (ym.month() == std::chrono::July) << ' '
              << (ym.year() == std::chrono::year(2021)) << ' ';
 
    ym += std::chrono::months {7};
    std::cout << (ym.month() == std::chrono::month(2)) << ' '
              << (ym.year() == std::chrono::year(2022)) << '\n';
}