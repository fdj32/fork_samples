#include <iostream>
#include <cassert>
#include <chrono>
 
int main()
{
    std::cout << std::boolalpha;
 
    constexpr auto monthsInYear {12};
    auto ymd {std::chrono::day(1)/std::chrono::July/2020};
 
    ymd -= std::chrono::years(10);
    std::cout << (ymd.month() == std::chrono::July) << ' '  // true
              << (ymd.year() == std::chrono::year(2010)) << ' ';  // true
 
    ymd += std::chrono::months(10 * monthsInYear + 11);
    std::cout << (ymd.month() == std::chrono::month(6)) << ' '  // true
              << (ymd.year() == std::chrono::year(2021)) << ' ';  // true
 
    // Handling the ymd += months "overflow" case.
 
    ymd = std::chrono::May/31/2021;  // ok
    std::cout << ymd.ok() << ' ';  // true
    ymd += std::chrono::months{1};  // bad date: June has only 30 days
    std::cout << ymd.ok() << ' ';  // false
    assert(ymd == std::chrono::June/31/2021);
 
    // Snap to the last day of the month, June 30:
    const auto ymd1 = ymd.year()/ymd.month()/std::chrono::last;
    std::cout << ymd1.ok() << ' '; // true
    assert(ymd1 == std::chrono::June/30/2021);
 
    // Overflow into the next month, July 1 (via converting to/from sys_days):
    const std::chrono::year_month_day ymd2 = std::chrono::sys_days{ymd};
    std::cout << ymd2.ok() << ' '; // true
    assert(ymd2 == std::chrono::July/1/2021);
}