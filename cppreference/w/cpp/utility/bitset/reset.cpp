#include <iostream>
#include <bitset>
 
int main()
{
    std::bitset<8> b(42);
    std::cout << "Bitset is         " << b << '\n';
    b.reset(1);
    std::cout << "After b.reset(1): " << b << '\n';
    b.reset();
    std::cout << "After b.reset():  " << b << '\n';
}