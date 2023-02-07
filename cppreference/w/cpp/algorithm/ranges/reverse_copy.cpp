#include <algorithm>
#include <iostream>
#include <string>
 
int main()
{
    std::string x{"12345"}, y(x.size(), ' ');
    std::cout << x << " → ";
#ifndef __clang__
    std::ranges::reverse_copy(x.begin(), x.end(), y.begin());
    std::cout << y << " → ";
    std::ranges::reverse_copy(y, x.begin());
#endif
    std::cout << x << '\n';
}