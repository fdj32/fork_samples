#include <iostream>
#include <iomanip>
#include <chrono>
 
void print(std::chrono::year_month_day const ymd) {
//  std::cout << ymd; // when C++20 stream operator<< ready, or:
    std::cout << static_cast<int>(ymd.year()) << '/'
              << std::setw(2) << std::setfill('0')
              << static_cast<unsigned>(ymd.month()) << '/'
              << std::setw(2) << static_cast<unsigned>(ymd.day());
}
 
int main()
{
    using namespace std::chrono;
    const auto today = sys_days{floor<days>(system_clock::now())};
    for (const year_month_day ymd : { {November/15/2020}, {November/15/2120}, today }) {
        print(ymd);
        const auto delta = (sys_days{ymd} - today).count();
        (delta < 0) ? std::cout << " was " << -delta << " day(s) ago\n" :
        (delta > 0) ? std::cout << " is " << delta << " day(s) from now\n"
                    : std::cout << " is today!\n";
    }
}