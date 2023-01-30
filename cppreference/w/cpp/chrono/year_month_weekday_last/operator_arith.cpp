#include <iostream>
#include <chrono>
using namespace std::chrono;
 
int main()
{
    std::cout << std::boolalpha;
 
    auto ymwdl {August/Tuesday[last]/2022};
    ymwdl += months(2);
    std::cout << (year_month_day{ymwdl} == October/25/2022) << ' ';
    ymwdl -= years(1); 
    std::cout << (year_month_day{ymwdl} == October/26/2021) << '\n';
}