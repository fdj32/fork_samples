#include <iostream>
#include <complex>
 
int main()
{
    std::cout << "Square root of -4 is "
              << std::sqrt(std::complex<double>(-4, 0)) << '\n'
              << "Square root of (-4,-0), the other side of the cut, is "
              << std::sqrt(std::complex<double>(-4, -0.0)) << '\n';
}