#include <array>
#include <chrono>
#include <iostream>
#include <string_view>
using namespace std::chrono;
using namespace std::literals;
 
int main()
{
    constexpr std::array weekdays {
        "Sunday"sv, "Monday"sv, "Tuesday"sv, "Wednesday"sv, 
        "Thursday"sv, "Friday"sv, "Saturday"sv
    };
    constexpr std::array quarters {
        "1st"sv, "2nd"sv, "3rd"sv, "4th"sv
    };
    constexpr auto mq {12 / 4}; // months per quarter        
    constexpr year y {2021y};
    std::cout << "In " << static_cast<int>(y) << " the\n";
    for (auto q = 1; q < 5; ++q) {
        const auto ls = y / month(q * mq) / Sunday[last];
        const auto ld = y / month(q * mq) / last;
        // subtract last Sunday from last day for day of week
        const auto index = (sys_days(ld) - sys_days(ls)).count();
        std::cout << quarters[q - 1] << " quarter ends on a "  
                  << weekdays[index] << (q < 4 ? ',':'.') << '\n';
    }
}