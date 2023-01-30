#include <iostream>
#include <chrono>
using namespace std::chrono;
 
int main()
{
    constexpr auto ymwdl1 {Tuesday[last]/11/2021};
    auto ymwdl2 = Tuesday[last]/11/2020;
    ymwdl2 += months(12);
    std::cout << std::boolalpha << (ymwdl1 == ymwdl2) << '\n';
}