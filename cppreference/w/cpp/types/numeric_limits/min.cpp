
 #include <cstddef>
#include <iomanip>
#include <iostream>
#include <limits>

template <typename T>
void print_one(std::string_view type_name)
{
    constexpr T min = std::numeric_limits<T>::min();
    std::cout 
        << std::dec << std::defaultfloat << std::setw(14) << type_name
        << " (" << std::setw(2) << sizeof(T) << " bytes): " << min;

    if constexpr (min != 0)
        std::cout << " or " << std::showbase << std::hex << std::hexfloat << min;

    std::cout << '\n';
}

#define SHOW(T) print_one<T>(#T)

int main()
{
    SHOW(bool);
    SHOW(short);
    SHOW(unsigned short);
    SHOW(signed);
    SHOW(unsigned);
    SHOW(std::ptrdiff_t);
    SHOW(std::size_t);
    SHOW(float);
    SHOW(double);
    SHOW(long double);
}
