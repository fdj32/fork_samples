
 #include <chrono>
#include <iostream>
using namespace std::chrono;

int main()
{
    constexpr auto third_friday = weekday_indexed(Friday, 3); // uses constructor (2)
    static_assert(third_friday == Friday[3]);

    weekday_indexed wdi = Tuesday[2]; // represents the 2nd Tuesday
    std::cout << year_month_day{ wdi / October / 2019y } << '\n';
}
