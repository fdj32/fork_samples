
 #include <cmath>
#include <iostream>

int main()
{
    // spot check for n == 1
    double x = 1.2345;
    std::cout << "j_1(" << x << ") = " << std::sph_bessel(1, x) << '\n';

    // exact solution for j_1
    std::cout << "(sin(x)/x² - cos(x)/x) = "
              << std::sin(x) / (x * x) - std::cos(x) / x << '\n';
}
