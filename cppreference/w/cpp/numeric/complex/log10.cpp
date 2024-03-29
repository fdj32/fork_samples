
 #include <iostream>
#include <cmath>
#include <complex>

int main()
{
    std::complex<double> z(0, 1); // r = 0, θ = pi/2
    std::cout << "2*log10" << z << " = " << 2. * std::log10(z) << '\n';

    std::complex<double> z2(sqrt(2.)/2, sqrt(2.)/2); // r = 1, θ = pi/4
    std::cout << "4*log10" << z2 << " = " << 4. * std::log10(z2) << '\n';

    std::complex<double> z3(-100, 0); // r = 100, θ = pi
    std::cout << "log10" << z3 << " = " << std::log10(z3) << '\n';
    std::complex<double> z4(-100, -0.0); // the other side of the cut
    std::cout << "log10" << z4 << " = " << std::log10(z4) << " "
                 "(the other side of the cut)\n"
                 "(note: pi/log(10) = " << std::acos(-1.)/std::log(10.) << ")\n";
}
