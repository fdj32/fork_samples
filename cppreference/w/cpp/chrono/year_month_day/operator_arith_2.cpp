
 #include <iostream>
#include <chrono>

int main()
{
    std::cout << std::boolalpha;

    auto ymd {std::chrono::day(1)/std::chrono::July/2021};

    ymd = ymd + std::chrono::months(4);
    std::cout << (ymd.month() == std::chrono::November) << ' '
              << (ymd.year() == std::chrono::year(2021)) << ' ';

    ymd = ymd - std::chrono::years(10);
    std::cout << (ymd.month() == std::chrono::month(11)) << ' '
              << (ymd.year() == std::chrono::year(2011)) << ' ';
}
