
 #include <cassert>
#include <iostream>
#include <chrono>

int main()
{
    std::chrono::month m {6};

    ++m;
    assert(m == std::chrono::month(7));

    --m;
    assert(m == std::chrono::month(6));

    m = std::chrono::December;
    m++; // rounds up to January
    assert(m.ok());
    std::cout << unsigned(m) << '\n';

    m = std::chrono::January;
    m--; // rounds down to December
    assert(m.ok());
    std::cout << unsigned(m) << '\n';
}
