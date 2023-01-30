#include <iostream>
#include <bitset>
 
int main()
{
    std::bitset<4> flops;
 
    std::cout << flops << '\n'
              << flops.flip(0) << '\n'
              << flops.flip(2) << '\n'
              << flops.flip() << '\n';
}