#include <cmath>
#include <iostream>
#include <numbers>
const auto pi2 = std::pow(std::numbers::pi,2);
int main()
{
#ifndef __clang__
    // spot checks for well-known values
    std::cout << "ζ(-1) = " << std::riemann_zeta(-1) << '\n'
              << "ζ(0) = " << std::riemann_zeta(0) << '\n'
              << "ζ(1) = " << std::riemann_zeta(1) << '\n'
              << "ζ(0.5) = " << std::riemann_zeta(0.5) << '\n'
              << "ζ(2) = " << std::riemann_zeta(2) << ' '
              << "(π²/6 = " << pi2/6 << ")\n";
#endif
}