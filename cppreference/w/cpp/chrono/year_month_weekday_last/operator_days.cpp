
 #include <iostream>
#include <chrono>
using namespace std::chrono;

int main()
{
    std::cout << std::boolalpha;

    constexpr auto ymwdl {Tuesday[last]/11/2021};
    static_assert(static_cast<local_days>(ymwdl) ==
                  static_cast<local_days>(November/30/2021));
    // convert from field-based to serial-based to add days
    constexpr auto sd = static_cast<sys_days>(ymwdl);
    constexpr year_month_day ymd {sd + days(10)};
    std::cout << (ymd == December/10/2021) << '\n';
}
