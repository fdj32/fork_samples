
 #include <iostream>
#include <chrono>
using namespace std::chrono;

int main()
{
    std::cout << std::boolalpha;

    constexpr auto ym {2021y/8};
    std::cout << (ym == year_month(year(2021), August)) << ' ';

    constexpr auto md {9/15d};
    std::cout << (md == month_day(September, day(15))) << ' ';

    constexpr auto mdl {October/last};
    std::cout << (mdl == month_day_last(month(10))) << ' ';

    constexpr auto mw {11/Monday[3]};
    std::cout << (mw == month_weekday(November, Monday[3])) << ' ';

    constexpr auto mwdl {December/Sunday[last]};
    std::cout << (mwdl == month_weekday_last(month(12), weekday_last(Sunday))) << ' ';

    // Those three year/month/day orders that people actually use on this planet:
    constexpr auto ymd {year(2021)/January/day(23)};
    static_assert(ymd == month{1}/23/2021);
    static_assert(ymd == day{23}/1/2021);
    std::cout << (ymd == year_month_day(2021y, month(January), 23d)) << '\n';
}
