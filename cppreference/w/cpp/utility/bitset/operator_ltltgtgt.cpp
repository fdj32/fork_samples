#include <iostream>
#include <bitset>
 
int main()
{
    std::bitset<8> b{0b01110010};
    std::cout << b << " (initial value)\n";
 
    for (; b.any(); b >>= 1) {
        for (; !b.test(0); b >>= 1) {
        }
        std::cout << b << '\n';
    }
 
    std::cout << b << " (final value)\n";
}