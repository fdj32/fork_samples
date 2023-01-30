#include <iostream>
#include <chrono>
using namespace std::chrono;
 
int main()
{
    std::cout << std::boolalpha;
 
    auto ymwdl {Tuesday[last]/November/2022};
    auto wdl = ymwdl.weekday_last();
    wdl = (wdl.weekday() + days(1))[last];
    ymwdl = {ymwdl.year() + years(1), ymwdl.month() - months(2), wdl};
    std::cout << (year_month_day(ymwdl) == September/27/2023) << '\n';
}