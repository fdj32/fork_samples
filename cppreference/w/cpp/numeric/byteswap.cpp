#include <bit>
#include <cstdint>
#include <concepts>
#include <iostream>
#include <iomanip>
 
template <std::integral T>
void dump(T v, char term = '\n') {
    std::cout << std::hex << std::uppercase << std::setfill('0')
              << std::setw(sizeof(T) * 2) << v << " : ";
    for (std::size_t i{}; i != sizeof(T); ++i, v >>= 8) {
        std::cout << std::setw(2) << static_cast<unsigned>(T(0xFF) & v) << ' ';
    }
    std::cout << std::dec << term;
}
 
int main()
{
#ifndef __clang__
    static_assert(std::byteswap('a') == 'a');
 
    std::cout << "byteswap for U16:\n";
    constexpr auto x = std::uint16_t(0xCAFE);
    dump(x);
    dump(std::byteswap(x));
 
    std::cout << "\nbyteswap for U32:\n";
    constexpr auto y = std::uint32_t(0xDEADBEEFu);
    dump(y);
    dump(std::byteswap(y));
 
    std::cout << "\nbyteswap for U64:\n";
    constexpr auto z = std::uint64_t{0x0123456789ABCDEFull};
    dump(z);
    dump(std::byteswap(z));
#endif
}