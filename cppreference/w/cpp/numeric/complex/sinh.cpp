
 #include <iostream>
#include <cmath>
#include <complex>

int main()
{
    std::cout << std::fixed;
    std::complex<double> z(1, 0); // behaves like real sinh along the real line
    std::cout << "sinh" << z << " = " << std::sinh(z)
              << " (sinh(1) = " << std::sinh(1) << ")\n";

    std::complex<double> z2(0, 1); // behaves like sine along the imaginary line
    std::cout << "sinh" << z2 << " = " << std::sinh(z2)
              << " ( sin(1) = " << std::sin(1) << ")\n";
}
