#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
// #pragma STDC FENV_ACCESS ON
const double pi = std::acos(-1); // or std::numbers::pi since C++20
int main()
{
    std::cout << "lgamma(10) = " << std::lgamma(10)
              << ",  log(9!) = " << std::log(2*3*4*5*6*7*8*9) << '\n'
              << "lgamma(0.5) = " << std::lgamma(0.5)
              << " , log(sqrt(pi)) = " << std::log(std::sqrt(pi)) << '\n';
    // special values
    std::cout << "lgamma(1) = " << std::lgamma(1) << '\n'
              << "lgamma(+Inf) = " << std::lgamma(INFINITY) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "lgamma(0) = " << std::lgamma(0) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_DIVBYZERO))
        std::cout << "    FE_DIVBYZERO raised\n";
}