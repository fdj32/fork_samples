#include <iostream>
#include <chrono>
using namespace std::chrono;
 
int main()
{
    constexpr std::chrono::year y {2020};
    std::cout << "The year is: " << int(y) << '\n';
 
    const year_month_day ymd{floor<days>(system_clock::now())};
    const std::chrono::year this_year{ymd.year()};
    std::cout << "This year is: " << int(this_year) << '\n';
}