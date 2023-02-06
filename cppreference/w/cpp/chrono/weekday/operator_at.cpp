#include <chrono>
#include <iostream>
using namespace std::chrono;
 
int main()
{
    constexpr auto second_tuesday_in_October_2019 =
                   year_month_day{ Tuesday[2] / October / 2019y };
 
    constexpr auto last_tuesday_in_October_2019 =
                   year_month_day { Tuesday[last] / October / 2019y };
#ifndef __clang__
    std::cout << second_tuesday_in_October_2019 << '\n'
              << last_tuesday_in_October_2019 << '\n'; 
#endif
}