
 #include <iostream>
#include <experimental/source_location>

template<typename T = std::experimental::source_location>
inline void pos(const T& location = T::current())
{
    std::cout
        << "("
        << location.line()
        << ':' 
        << location.column()
        << ") ";
}

auto main() -> int
{
    pos(); std::cout << "Proxima\n";
    pos(); std::cout << "Centauri\n";
}
