
 #include <iostream>
#include <chrono>
using namespace std::chrono_literals;

int main()
{
    std::cout << std::boolalpha;

    constexpr std::chrono::year_month ym1 {3030y, std::chrono::July};
    std::cout << ym1.ok() << ' ';

    constexpr std::chrono::year_month ym2 {std::chrono::year(2020)/16};
    std::cout << ym2.ok() << '\n';
}
