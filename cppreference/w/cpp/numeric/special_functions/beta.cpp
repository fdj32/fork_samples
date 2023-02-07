#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>
#ifndef __clang__
double binom(int n, int k) { return 1/((n+1)*std::beta(n-k+1,k+1)); }
#endif
int main()
{
    std::cout << "Pascal's triangle:\n";
    for(int n = 1; n < 10; ++n) {
        std::cout << std::string(20-n*2, ' ');
#ifndef __clang__
        for(int k = 1; k < n; ++k)
            std::cout << std::setw(3) << binom(n,k) << ' ';
#endif
        std::cout << '\n';
    }
}