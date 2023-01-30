#include <iostream>
#include <chrono>
 
int main()
{
    std::cout << std::boolalpha;
 
    auto ymwi {1/std::chrono::Wednesday[2]/2021};
    ymwi += std::chrono::years(5);
    std::cout << (static_cast<std::chrono::year_month_day>(ymwi) ==
                              std::chrono::year(2026)/1/14) << ' ';
    ymwi -= std::chrono::months(1);
    std::cout << (static_cast<std::chrono::year_month_day>(ymwi) == 
                              std::chrono::day(10)/12/2025) << '\n';
}