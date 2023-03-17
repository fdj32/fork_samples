
 #include <complex>
#include <functional>
#include <iostream>

int main()
{
    constexpr std::complex z1{1., 2.}, z2{3., 4.};

    std::cout << std::showpos
              << std::multiplies{}(z1, z2) << ' ' << z1 * z2 << '\n'
              << std::multiplies{}(z1, 5.) << ' ' << z1 * 5. << '\n'
              << std::multiplies{}(5., z1) << ' ' << 5. * z1 << '\n'
              ;
}
