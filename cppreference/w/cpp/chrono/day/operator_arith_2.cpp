#include <chrono>
#include <cassert>
 
int main()
{
    std::chrono::day d {15};
 
    d = d + std::chrono::days(2);
    assert(d == std::chrono::day(17));
 
    d = d - std::chrono::days(3);
    assert(d == std::chrono::day(14));
 
    constexpr std::chrono::days ds = std::chrono::day(16) - std::chrono::day(14);
    static_assert(ds == std::chrono::days(2));
}