
 #include <iostream>
#include <chrono>

int main()
{
    std::cout << std::boolalpha;

    auto ym {std::chrono::year(2021)/std::chrono::July};

    ym = ym + std::chrono::months(14);
    std::cout << (ym.month() == std::chrono::September) << ' '
              << (ym.year() == std::chrono::year(2022)) << ' ';

    ym = ym - std::chrono::years(3);
    std::cout << (ym.month() == std::chrono::month(9)) << ' '
              << (ym.year() == std::chrono::year(2019)) << ' ';

    ym = ym + (std::chrono::September - std::chrono::month(2));
    std::cout << (ym.month() == std::chrono::April) << ' '
              << (ym.year() == std::chrono::year(2020)) << '\n';
}
