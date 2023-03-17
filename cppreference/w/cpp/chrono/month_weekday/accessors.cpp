
 #include <iostream>
#include <chrono>

int main()
{
    std::cout << std::boolalpha;

    auto mwdi {std::chrono::March/std::chrono::Friday[1]}; // 1st Friday in a March
    std::cout << (std::chrono::year_month_day{mwdi/2024} == 
                  std::chrono::year_month_day{std::chrono::March/1/2024})
                  << ' ';
    auto index = mwdi.weekday_indexed().index();
    auto weekday = mwdi.weekday_indexed().weekday();
    mwdi = {mwdi.month(), weekday[index + 4]}; // 5th Friday in a March
    std::cout << (std::chrono::year_month_day{mwdi/2024} == 
                  std::chrono::year_month_day{std::chrono::March/29/2024})
                  << '\n';
}
