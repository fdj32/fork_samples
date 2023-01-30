#include <cassert>
#include <chrono>
 
int main()
{
    std::chrono::year y {2020};
 
    y = y + std::chrono::years(12);
    assert(y == std::chrono::year(2032));
 
    y = y - std::chrono::years(33);
    assert(y == std::chrono::year(1999));
 
    constexpr std::chrono::years ys = std::chrono::year(2025) - std::chrono::year(2020);
    static_assert(ys == std::chrono::years(5));
}