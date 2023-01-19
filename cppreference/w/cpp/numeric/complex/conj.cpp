#include <iostream>
#include <complex>
 
int main()
{
    std::complex<double> z(1,2);
    std::cout << "The conjugate of " << z << " is " << std::conj(z) << '\n'
              << "Their product is " << z*std::conj(z) << '\n';
}