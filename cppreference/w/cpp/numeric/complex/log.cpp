
 #include <iostream>
#include <cmath>
#include <complex>

int main()
{
    std::complex<double> z{0, 1}; // r = 1, θ = pi/2
    std::cout << "2*log" << z << " = " << 2.0 * std::log(z) << '\n';

    std::complex<double> z2{sqrt(2.0) / 2, sqrt(2.0) / 2}; // r = 1, θ = pi/4
    std::cout << "4*log" << z2 << " = " << 4.0* std::log(z2) << '\n';

    std::complex<double> z3{-1, 0}; // r = 1, θ = pi
    std::cout << "log" << z3 << " = " << std::log(z3) << '\n';
    std::complex<double> z4{-1, -0.0}; // the other side of the cut
    std::cout << "log" << z4 << " (the other side of the cut) = " << std::log(z4) << '\n';
}
