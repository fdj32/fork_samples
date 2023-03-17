
 #include <iostream>
#include <complex>

int main()
{
    std::complex<double> z(1, 1);
    std::cout << z << " cartesian is rho = " << std::abs(z)
              << " theta = " << std::arg(z) << " polar\n";
}
