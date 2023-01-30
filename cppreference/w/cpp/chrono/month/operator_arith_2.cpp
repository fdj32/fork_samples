#include <cassert>
#include <chrono>
 
int main()
{
    std::chrono::month m {6};
 
    m = m + std::chrono::months(2);
    assert(m == std::chrono::month(8));
 
    m = m - std::chrono::months(3);
    assert(m == std::chrono::month(5));
 
    constexpr std::chrono::months ms = std::chrono::month(8) - std::chrono::month(6);
    static_assert(ms == std::chrono::months(2));
}