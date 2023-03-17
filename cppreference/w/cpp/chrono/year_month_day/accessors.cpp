
 #include <chrono>

int main()
{
    constexpr std::chrono::year_month_day ymd {std::chrono::July/1/2021};

    static_assert(ymd.year() == std::chrono::year(2021));
    static_assert(ymd.month() == std::chrono::month(7));
    static_assert(ymd.day() == std::chrono::day(1));
 }
