#include <iostream>
#include <bitset>
 
int main()
{
    std::bitset<8> b;
    std::cout << b << '\n';
    std::cout << b.set() << '\n';
    std::cout << b.reset() << '\n';    
 
    for (size_t i = 1; i < b.size(); i += 2)
        b.set(i);
 
    std::cout << b << '\n';
}
