#include <chrono>
 
int main()
{
    constexpr auto ymd1 {std::chrono::day(1)/std::chrono::July/2020};
    static_assert(ymd1.ok());
 
    constexpr auto ymd2 {std::chrono::year(2020)/7/42};
    static_assert(not ymd2.ok());
 
    constexpr auto ymd3 {std::chrono::February/29/2020}; // ok, leap year
    static_assert(ymd3.ok());
 
    constexpr auto ymd4 = ymd3 + std::chrono::years{1}; // bad, not a leap year
    static_assert(ymd4 == std::chrono::February/29/2021 and not ymd4.ok());
 
    // to fix the bad date we may want to snap to the last day of the month:
    if constexpr (!ymd4.ok()) {
        constexpr auto ymd = ymd4.year()/ymd4.month()/std::chrono::last;
        static_assert(ymd == std::chrono::February/28/2021 and ymd.ok());
    }
 
    // or we may want to overflow to the next month:
    if constexpr (!ymd4.ok()) {
        constexpr auto st = std::chrono::sys_time<std::chrono::days>{ymd4};
        constexpr auto ymd = std::chrono::year_month_day{st};
        static_assert(ymd == std::chrono::March/1/2021 and ymd.ok());
    }
}