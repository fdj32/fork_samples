
 #include <iostream>
#include <chrono>

int main()
{
    std::cout << std::boolalpha;

    std::chrono::weekday wd {5}; // Friday is 5
    wd += std::chrono::days(2);
    std::cout << (wd == std::chrono::weekday(0)) << ' '
              << (wd == std::chrono::Sunday) << ' ';

    wd -= std::chrono::days(3);
    std::cout << (wd == std::chrono::weekday(4)) << ' '
              << (wd == std::chrono::Thursday) << ' ';

    wd = std::chrono::Wednesday;
    wd += std::chrono::days{8}; // ((3 += 8 == 11)% 7) == 4;
    std::cout << (wd == std::chrono::Thursday) << ' ';

    wd -= (std::chrono::Sunday - std::chrono::Tuesday); // -= -2
    // (4 -= -2) == 6
    std::cout << (wd == std::chrono::Saturday) << '\n';
}
