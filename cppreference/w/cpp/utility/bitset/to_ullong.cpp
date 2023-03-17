
 #include <iostream>
#include <bitset>
#include <limits>

int main()
{
    std::bitset<std::numeric_limits<unsigned long long>::digits> b(
        0x123456789abcdef0LL
    );

    std::cout << b << "  " << std::hex << b.to_ullong() << '\n';
    b.flip();
    std::cout << b << "  " << b.to_ullong() << '\n';
}
