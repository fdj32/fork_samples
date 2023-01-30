#include <cassert>
#include <chrono>
 
int main()
{
    std::chrono::day d {15};
 
    d += std::chrono::days(2);
    assert(d == std::chrono::day(17));
 
    d -= std::chrono::days{3};
    assert(d == std::chrono::day(14));
}