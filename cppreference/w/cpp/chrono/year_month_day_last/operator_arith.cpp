
 #include <iostream>
#include <chrono>

int main()
{
    std::cout << std::boolalpha;

    auto ymdl {11/std::chrono::last/2020};
    ymdl += std::chrono::years(15);
    std::cout << (ymdl.day() == std::chrono::day(30)) << ' '
              << (ymdl.month() == std::chrono::November) << ' '
              << (ymdl.year() == std::chrono::year(2035)) << ' ';
    ymdl -= std::chrono::months(6);
    std::cout << (ymdl.day() == std::chrono::day(31)) << ' '
              << (ymdl.month() == std::chrono::May) << ' '
              << (ymdl.year() == std::chrono::year(2035)) << '\n';
}
