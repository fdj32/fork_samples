
 #include <cerrno>
#include <cfenv>
#include <cmath>
#include <iostream>
#include <numbers>

// #pragma STDC FENV_ACCESS ON
const double pi = std::numbers::pi; // or std::acos(-1) before C++20

int main()
{
    // typical usage
    std::cout << "cos(pi/3) = " << std::cos(pi / 3) << '\n'
              << "cos(pi/2) = " << std::cos(pi / 2) << '\n'
              << "cos(-3*pi/4) = " << std::cos(-3 * pi / 4) << '\n';

    // special values
    std::cout << "cos(+0) = " << std::cos(0.0) << '\n'
              << "cos(-0) = " << std::cos(-0.0) << '\n';

    // error handling
    std::feclearexcept(FE_ALL_EXCEPT);

    std::cout << "cos(INFINITY) = " << std::cos(INFINITY) << '\n';
    if (std::fetestexcept(FE_INVALID))
        std::cout << "    FE_INVALID raised\n";
}
