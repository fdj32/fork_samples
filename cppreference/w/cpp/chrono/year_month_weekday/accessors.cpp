
 #include <iostream>
#include <chrono>

int main()
{
    std::cout << std::boolalpha;

    constexpr auto ym {std::chrono::year(2021)/std::chrono::January};
    constexpr auto wdi {std::chrono::Wednesday[1]};
    auto ymwdi {ym/wdi};
    auto index = ymwdi.index() + 1;
    auto weekday = ymwdi.weekday() + std::chrono::days(1);
    ymwdi = {ymwdi.year()/ymwdi.month()/weekday[index]};
    // Second Thursday in January, 2021
    std::cout << (std::chrono::year_month_day{ymwdi} == 
                  std::chrono::January/14/2021) << '\n';
}
