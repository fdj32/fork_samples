
 #include <iostream>
#include <chrono>
using namespace std::chrono;

int main()
{
    std::cout << std::boolalpha;

    auto mwdl {March/Friday[last]}; // Last Friday in a March
    auto ywdl {year(2024)/mwdl};
    std::cout << (year_month_day{ywdl} == 
                  year_month_day{March/29/2024}) << ' ';
    // Last Friday of the next month, in 2024
    mwdl = {(mwdl.month() + months(1))/mwdl.weekday_last()};
    ywdl = {year(2024)/mwdl}; 
    std::cout << (year_month_day{ywdl} == 
                  year_month_day{April/26/2024}) << '\n';
}
