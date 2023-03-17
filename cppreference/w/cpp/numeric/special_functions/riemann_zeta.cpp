
 #include <cmath>
#include <iostream>
#include <numbers>

constexpr auto π = std::numbers::pi;

int main()
{
    // spot checks for well-known values
    std::cout << "ζ(-1)  = " << std::riemann_zeta(-1) << '\n'
              << "ζ(0)   = " << std::riemann_zeta(0) << '\n'
              << "ζ(1)   = " << std::riemann_zeta(1) << '\n'
              << "ζ(0.5) = " << std::riemann_zeta(0.5) << '\n'
              << "ζ(2)   = " << std::riemann_zeta(2) << '\n'
              << "π²/6   = " << π * π / 6 << '\n';
}
