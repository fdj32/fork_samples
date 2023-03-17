
 #include <iostream>
#include <chrono>

int main()
{
    std::cout << std::boolalpha;

    std::chrono::weekday_indexed wdi {std::chrono::Tuesday[2]}; // 2nd Tuesday of a month
    std::cout << (std::chrono::year_month_day{wdi/10/2019} == 
                  std::chrono::year_month_day{std::chrono::October/8/2019}) << ' ';

    wdi = {wdi.weekday() + std::chrono::days(2), wdi.index()}; // 2nd Tuesday => 2nd Thursday
    std::cout << (std::chrono::year_month_day{wdi/10/2019} == 
                  std::chrono::year_month_day{std::chrono::October/10/2019}) << '\n';
}
