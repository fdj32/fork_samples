#include <iostream>
#include <chrono>
using namespace std::chrono;
 
int main()
{
    std::cout << std::boolalpha;
 
    constexpr auto ymwd {Tuesday[2]/11/2021};
    // convert from field-based to serial-based to add hours
    constexpr auto sd = sys_days{ymwd} + 24h;
    constexpr auto ymd = floor<days>(sd);
    std::cout << (ymd == November/10/2021) << '\n';
}