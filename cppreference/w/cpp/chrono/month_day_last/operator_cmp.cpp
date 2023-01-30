#include <iostream>
#include <chrono>
 
int main()
{
    constexpr auto mdl1 {std::chrono::February/std::chrono::last};
    constexpr std::chrono::month_day_last mdl2 {std::chrono::month(2)};
    std::cout << std::boolalpha << (mdl1 == mdl2) << '\n';
 
    static_assert(mdl1 <= mdl2);
}