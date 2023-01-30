#include <iostream>
#include <chrono>
 
int main()
{
    std::cout << std::boolalpha;
 
    constexpr auto md1 {std::chrono::July/15};
    std::cout << (md1.ok()) << ' ';
    constexpr std::chrono::month_day md2 {std::chrono::month(14), std::chrono::day(42)};
    std::cout << (md2.ok()) << ' ';
    constexpr auto md3 {std::chrono::February/29};
    std::cout << (md3.ok()) << '\n';
}