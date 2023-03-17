
 #include <complex>
#include <functional>
#include <iostream>

int main()
{
    constexpr std::complex z1{8.0, 4.0}, z2{1.0, 2.0};

    std::cout << std::showpos
              << std::divides{}(z1, z2) << ' ' << z1 / z2 << '\n'
              << std::divides{}(z1, 5.) << ' ' << z1 / 5. << '\n'
              << std::divides{}(6., z2) << ' ' << 6. / z2 << '\n'
              ;
}
