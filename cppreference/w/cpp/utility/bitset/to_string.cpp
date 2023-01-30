#include <iostream>
#include <bitset>
 
int main()
{
    std::bitset<8> b{42};
    std::cout << b.to_string() << '\n'
              << b.to_string('*') << '\n'
              << b.to_string('O', 'X') << '\n';
}