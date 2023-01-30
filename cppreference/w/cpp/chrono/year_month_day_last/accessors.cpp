#include <iostream>
#include <chrono>
 
int main()
{
    std::cout << std::boolalpha;
 
    constexpr auto ymdl {std::chrono::last/11/2020};
    std::cout << (ymdl.day() == std::chrono::day(30)) << ' '
              << (ymdl.month() == std::chrono::November) << ' '
              << (ymdl.year() == std::chrono::year(2020)) << ' ';
    constexpr auto mdl = ymdl.month_day_last();
    std::cout << (mdl == (std::chrono::November/std::chrono::last)) << '\n';
}