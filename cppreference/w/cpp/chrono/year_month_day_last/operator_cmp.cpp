#include <iostream>
#include <chrono>
 
int main()
{
    std::cout << std::boolalpha;
 
    auto ymdl1 {11/std::chrono::last/2020};
    auto mdl {std::chrono::last/std::chrono::November};
    auto ymdl2 {mdl/2020};
    std::cout << (ymdl1 == ymdl2) << ' ';
    ymdl1 -= std::chrono::months{2};
    ymdl2 -= std::chrono::months{1};
    std::cout << (ymdl1 < ymdl2) << '\n';
}