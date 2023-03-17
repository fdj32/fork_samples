
 #include <cerrno>
#include <cfenv>
#include <cmath>
#include <cstring>
#include <iostream>

#ifndef __GNUC__
#pragma STDC FENV_ACCESS ON
#endif

int main()
{
    std::cout << "fdim(4, 1) = " << std::fdim(4, 1) << '\n'
              << "fdim(1, 4) = " << std::fdim(1, 4) << '\n'
              << "fdim(4,-1) = " << std::fdim(4, -1) << '\n'
              << "fdim(1,-4) = " << std::fdim(1, -4) << '\n';

    // error handling 
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);

    std::cout << "fdim(1e308, -1e308) = " << std::fdim(1e308, -1e308) << '\n';

    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_OVERFLOW))
        std::cout << "    FE_OVERFLOW raised\n";
}
