#include <cmath>
#include <iostream>
int main()
{
    double hpi = std::acos(-1)/2;
#ifndef __clang__
    std::cout << "E(0) = " << std::comp_ellint_2(0) << '\n'
              << "π/2 = " << hpi << '\n'
              << "E(1) = " << std::comp_ellint_2(1) << '\n'
              << "E(1, π/2) = " << std::ellint_2(1, hpi) << '\n';
#endif
}