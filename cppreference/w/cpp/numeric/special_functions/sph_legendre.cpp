
 #include <cmath>
#include <iostream>
#include <numbers>

int main()
{
    // spot check for l=3, m=0
    double x = 1.2345;
    std::cout << "Y_3^0(" << x << ") = " << std::sph_legendre(3, 0, x) << '\n';

    // exact solution
    std::cout << "exact solution = "
              << 0.25 * std::sqrt(7 / std::numbers::pi) * (5 * std::pow(std::cos(x), 3)
                 - 3 * std::cos(x))
              << '\n';
}
