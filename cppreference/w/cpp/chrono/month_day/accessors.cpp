
 #include <iostream>
#include <chrono>

int main()
{
    std::cout << std::boolalpha;

    constexpr auto md {std::chrono::July/15};  
    std::cout << (md.month() == std::chrono::month(7)) << ' ';
    std::cout << (md.day() == std::chrono::day(15)) << '\n';
}
