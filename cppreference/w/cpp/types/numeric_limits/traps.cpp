
 #include <iostream>
#include <limits>

int main()
{
    std::cout << std::boolalpha
              << "bool:     traps = " << std::numeric_limits<bool>::traps << '\n'
              << "char:     traps = " << std::numeric_limits<char>::traps << '\n'
              << "char16_t: traps = " << std::numeric_limits<char16_t>::traps << '\n'
              << "long:     traps = " << std::numeric_limits<long>::traps << '\n'
              << "float:    traps = " << std::numeric_limits<float>::traps << '\n';
}
