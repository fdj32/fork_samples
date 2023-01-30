#include <iostream>
#include <chrono>
 
int main()
{
    constexpr auto wdl1 {std::chrono::Tuesday[std::chrono::last]};
    constexpr std::chrono::weekday_last wdl2 {std::chrono::weekday(2)};
    std::cout << std::boolalpha
              << (wdl1 == wdl2) << ' '
              << (wdl1 == std::chrono::Wednesday[std::chrono::last]) << '\n';
}