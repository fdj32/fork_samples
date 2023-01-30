#include <iostream>
#include <chrono>
 
int main()
{
    std::cout << std::boolalpha;
 
    auto ymdl {11/std::chrono::last/2020};
    ymdl = std::chrono::years(10) + ymdl;
    std::cout << (ymdl == std::chrono::day(30)/
                          std::chrono::November/
                          std::chrono::year(2030)) << ' ';
    ymdl = ymdl - std::chrono::months(6);
    std::cout << (ymdl == std::chrono::day(31)/
                          std::chrono::May/
                          std::chrono::year(2030)) << '\n';
}