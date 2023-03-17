
 #include <chrono>
#include <iostream>

int main()
{
    using namespace std::chrono_literals;
    constexpr auto mo_da = std::chrono::month_day(std::chrono::February, 29d);
    std::cout << static_cast<unsigned>(mo_da.day()) << '/' 
              << static_cast<unsigned>(mo_da.month()) << '\n';
}
