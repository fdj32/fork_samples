
 #include <iostream>
#include <chrono>

int main()
{
    constexpr auto ymd1 {std::chrono::day(1)/7/2021};
    constexpr auto ymd2 {std::chrono::year(2021)/7/1};
    std::cout << std::boolalpha << (ymd1 == ymd2) << '\n';

    static_assert(ymd1 <= ymd2);
}
