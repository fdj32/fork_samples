#include <iostream>
#include <chrono>
 
int main()
{
    using namespace std::chrono;
 
    constexpr year_month ym1 {year(2021), month(7)};
    constexpr year_month ym2 {year(2021)/7};
 
    std::cout << std::boolalpha << (ym1 == ym2) << '\n';
 
    static_assert(
        (2020y/1 < 2020y/2) && (2020y/2 == 2020y/2) && (2020y/3 <= 2021y/3)
     && (2023y/1 > 2020y/2) && (3020y/2 != 2020y/2) && (2020y/3 >= 2020y/3)
    );
}