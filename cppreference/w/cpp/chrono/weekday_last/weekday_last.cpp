#include <chrono>
#include <iostream>
using namespace std::chrono;
 
int main() {
    const year_month_day ymd { floor<days>(system_clock::now()) };
    const weekday_last wdl { Sunday[last] }; // A last Sunday of a month
    const year_month_day last_sun { ymd.year() / ymd.month() / wdl };
 
    std::cout << "The last Sunday of current month falls on "
              << (int)last_sun.year() << '/'
              << (unsigned)last_sun.month() << '/'
              << (unsigned)last_sun.day() << '\n';
}