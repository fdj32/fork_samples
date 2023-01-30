#include <chrono>
 
int main()
{
    constexpr std::chrono::weekday_indexed wdi1 {std::chrono::Wednesday[2]};
    constexpr std::chrono::weekday_indexed wdi2 {std::chrono::weekday(3), 2};
    static_assert(wdi1 == wdi2);
}