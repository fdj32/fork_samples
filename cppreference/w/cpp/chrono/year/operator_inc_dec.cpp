
 #include <iostream>
#include <chrono>

int main()
{
    std::cout << std::boolalpha;

    std::chrono::year y {2020};
    std::cout << (++y == std::chrono::year(2021)) << ' ';
    std::cout << (--y == std::chrono::year(2020)) << '\n';

    using namespace std::literals::chrono_literals;
    y = 32767y;
    y++; //< unspecified, see Notes
    std::cout << static_cast<int>(y) << '\n';
}
