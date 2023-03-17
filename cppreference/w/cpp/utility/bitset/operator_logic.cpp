
 #include <iostream>
#include <string>
#include <bitset>

int main()
{
    const std::string pattern_str{"1001"};
    std::bitset<16> pattern{pattern_str}, dest;

    for (std::size_t i = dest.size()/pattern_str.size(); i != 0; --i) {
        dest <<= pattern_str.size();
        dest |= pattern;
        std::cout << dest << " (i = " << i << ")\n";
    }

    std::cout << ~dest << " (~dest)\n";
}
