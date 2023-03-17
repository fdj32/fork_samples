
 #include <cassert>
#include <chrono>

int main()
{
    std::chrono::day d {15};

    ++d;
    assert(d == std::chrono::day(16));

    --d;
    assert(d == std::chrono::day(15));
}
