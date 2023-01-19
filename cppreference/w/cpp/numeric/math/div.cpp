#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cassert>
 
std::string euclidean_division_string(int dividend, int divisor)
{
    auto dv = std::div(dividend, divisor);
    assert(dividend == divisor * dv.quot + dv.rem);
    assert(dv.quot == dividend / divisor);
    assert(dv.rem == dividend % divisor);
    auto sgn = [](int n){ return n > 0 ? 1 : (n < 0 ? -1 : 0);}; //Sign function
    if (dv.rem != 0) assert(sgn(dv.rem) == sgn(dividend));
 
    return (std::ostringstream() << std::showpos << dividend << " = " 
             << divisor << " * (" << dv.quot << ") " 
             << std::showpos << dv.rem).str();
}
 
std::string itoa(int n, int radix /*[2..16]*/)
{
    std::string buf;
    std::div_t dv{}; dv.quot = n;
    do {
        dv = std::div(dv.quot, radix);
        buf += "0123456789abcdef"[std::abs(dv.rem)];  // string literals are arrays
    } while(dv.quot);
    if (n < 0)
        buf += '-';
 
    return {buf.rbegin(), buf.rend()};
}
 
int main()
{
    std::cout << euclidean_division_string(369, 10) << '\n'
              << euclidean_division_string(369, -10) << '\n'
              << euclidean_division_string(-369, 10) << '\n'
              << euclidean_division_string(-369, -10) << "\n\n";
 
    std::cout << itoa(12345, 10) << '\n'
              << itoa(-12345, 10) << '\n'
              << itoa(42, 2) << '\n'
              << itoa(65535, 16) << '\n';
}