#include <chrono>
#include <iostream>
 
int main()
{
    std::cout << "i: C: ISO: Weekday:\n";
 
    for (unsigned i{0}; i != 8; ++i) {
        const std::chrono::weekday w{i};
        std::cout << i << "  "
                  << w.c_encoding() << "  "
                  << w.iso_encoding() << "    "
                  << w << '\n';
    }
}