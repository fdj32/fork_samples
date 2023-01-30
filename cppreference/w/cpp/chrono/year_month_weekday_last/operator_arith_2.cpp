#include <iostream>
#include <chrono>
using namespace std::chrono;
 
int main()
{
    std::cout << std::boolalpha;
 
    constexpr auto ymwdl1 {Tuesday[last]/11/2021};
    auto ymwdl2 = ymwdl1;
    ymwdl2 = months(12) + ymwdl2;
    ymwdl2 = ymwdl2 - years(1);
    std::cout << (ymwdl1 == ymwdl2) << '\n';
}