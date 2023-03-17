
 #include <cerrno>
#include <cfenv>
#include <cmath>
#include <iostream>

// #pragma STDC FENV_ACCESS ON
const double pi = std::acos(-1); // or C++20's std::numbers::pi

int main()
{
    // typical usage
    std::cout << "tan(1*pi/4) = " << std::tan(1*pi/4) << '\n' // 45°
              << "tan(3*pi/4) = " << std::tan(3*pi/4) << '\n' // 135°
              << "tan(5*pi/4) = " << std::tan(5*pi/4) << '\n' // -135°
              << "tan(7*pi/4) = " << std::tan(7*pi/4) << '\n'; // -45°

    // special values
    std::cout << "tan(+0) = " << std::tan(0.0) << '\n'
              << "tan(-0) = " << std::tan(-0.0) << '\n';

    // error handling
    std::feclearexcept(FE_ALL_EXCEPT);

    std::cout << "tan(INFINITY) = " << std::tan(INFINITY) << '\n';
    if (std::fetestexcept(FE_INVALID))
        std::cout << "    FE_INVALID raised\n";
}
