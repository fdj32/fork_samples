#include <iostream>
#include <chrono>
using namespace std::chrono;
 
int main()
{
    constexpr auto ymwdi1 {Wednesday[1]/January/2021};
    constexpr year_month_weekday ymwdi2 {year(2021), month(1), weekday(3)[1]};
    std::cout << std::boolalpha << (ymwdi1 == ymwdi2) << '\n';
}