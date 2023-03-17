
 #include <iostream>
#include <chrono>

int main()
{
    std::cout << std::boolalpha;

    constexpr auto ym {std::chrono::year(2021)/std::chrono::July};  
    std::cout << (ym.year() == std::chrono::year(2021)) << ' ';
    std::cout << (ym.month() == std::chrono::month(7)) << '\n';

}
