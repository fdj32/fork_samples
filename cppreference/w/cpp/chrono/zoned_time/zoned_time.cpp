#include <chrono>
#include <iostream>
#include <string_view>
 
int main()
{
#ifndef __clang__
    using std::chrono_literals::operator""y;
    using std::operator""sv;
 
    const auto now = std::chrono::floor<std::chrono::minutes>(std::chrono::system_clock::now());
 
    {
        std::cout << std::chrono::zoned_time{} << " : default\n";
    }
    {
        constexpr std::string_view location {"America/Phoenix"sv};
        std::cout << std::chrono::zoned_time{ location } << " : " << location << '\n';
    }
    {
        const std::chrono::time_zone* TimeZonePtr = std::chrono::locate_zone("UTC");
        std::cout << std::chrono::zoned_time{ TimeZonePtr } << " : UTC time zone\n";
    }
    {
        constexpr auto location{"Europe/Rome"sv};
        std::cout << std::chrono::zoned_time{ location, std::chrono::local_days{2021y/12/31} }
                  << " : " << location << '\n';
    }
    {
        constexpr auto location {"Europe/Rome"sv};
        constexpr auto some_date = std::chrono::sys_time<std::chrono::days>{2021y/12/31};
        std::cout << std::chrono::zoned_time{ location, some_date } << " : " << location << '\n';
    }
    {
        constexpr auto location {"Europe/Rome"sv};
        std::cout << std::chrono::zoned_time{ location, now } << " : " << location << '\n';
    }
    {
        constexpr auto NewYork {"America/New_York"sv};
        constexpr auto Tokyo {"Asia/Tokyo"sv};
        const std::chrono::zoned_time tz_Tokyo {Tokyo, now};
        const std::chrono::zoned_time tz_NewYork {NewYork, now};
        std::cout << std::chrono::zoned_time{ Tokyo, tz_NewYork } << " : " << Tokyo << '\n';
        std::cout << std::chrono::zoned_time{ NewYork, tz_Tokyo } << " : " << NewYork << '\n';
    }
#endif
}