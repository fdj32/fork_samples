
 #include <complex>
#include <functional>
#include <iostream>

int main()
{
    constexpr std::complex z(4, 2);

    std::cout << z << ' ' << -z << ' ' << std::negate{}(z) << '\n';
}
