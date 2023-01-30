#include <chrono>
#include <iostream>
 
using namespace std::chrono;
 
int main()
{
    std::cout << std::boolalpha;
 
    auto mdl {February/last}; // Last day of a February
    auto ymdl {year(2020) / mdl};
    std::cout << (year_month_day{ymdl} == year_month_day{February/29/2020}) << ' ';
 
    mdl = (mdl.month() + months(1)) / last; // Last day of the next month, in 2020
    ymdl = year(2020) / mdl;
    std::cout << (year_month_day{ymdl} == year_month_day{March/31/2020}) << '\n';
}