#include <iostream>
#include <cmath>
#include <cfenv>
 
int main()
{
#pragma STDC FENV_ACCESS ON
    std::fesetround(FE_TONEAREST);
    std::cout << "rounding to nearest: \n"
              << "nearbyint(+2.3) = " << std::nearbyint(2.3)
              << "  nearbyint(+2.5) = " << std::nearbyint(2.5)
              << "  nearbyint(+3.5) = " << std::nearbyint(3.5) << '\n'
              << "nearbyint(-2.3) = " << std::nearbyint(-2.3)
              << "  nearbyint(-2.5) = " << std::nearbyint(-2.5)
              << "  nearbyint(-3.5) = " << std::nearbyint(-3.5) << '\n';
 
    std::fesetround(FE_DOWNWARD);
    std::cout << "rounding down:\n"
              << "nearbyint(+2.3) = " << std::nearbyint(2.3)
              << "  nearbyint(+2.5) = " << std::nearbyint(2.5)
              << "  nearbyint(+3.5) = " << std::nearbyint(3.5) << '\n'
              << "nearbyint(-2.3) = " << std::nearbyint(-2.3)
              << "  nearbyint(-2.5) = " << std::nearbyint(-2.5)
              << "  nearbyint(-3.5) = " << std::nearbyint(-3.5) << '\n';
 
    std::cout << "nearbyint(-0.0) = " << std::nearbyint(-0.0)  << '\n'
              << "nearbyint(-Inf) = " << std::nearbyint(-INFINITY) << '\n';
}