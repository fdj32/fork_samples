
 #include <chrono>
#include <iostream>
#include <iomanip>

int main()
{
    constexpr std::chrono::weekday friday{5};  // uses overload (2)
    static_assert(friday == std::chrono::Friday);

    for (int y {2020}; y <= 2023; ++y) {
        const std::chrono::year cur_year{y};
        for (int cur_month{1}; cur_month != 13; ++cur_month) {
            const std::chrono::year_month_day ymd{ cur_year / cur_month / 13 };
            const std::chrono::weekday cur_weekday{ std::chrono::sys_days{ ymd } };  // (3)
            if (cur_weekday == friday) {
            //  std::cout << ymd << " is " << friday << '\n';
                std::cout << int(ymd.year()) << '-' << std::setw(2) << std::setfill('0')
                          << unsigned(ymd.month()) << '-'
                          << unsigned(ymd.day()) << " is Fri\n";
            }
        }
    }
}
