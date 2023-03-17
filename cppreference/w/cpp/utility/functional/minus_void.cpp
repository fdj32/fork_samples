
 #include <complex>
#include <functional>
#include <iostream>

int main()
{
    constexpr std::complex<int> z(4, 2);

    std::cout << std::minus<>{}(z, 1) << ' ' << (z - 1) << '\n';
}
