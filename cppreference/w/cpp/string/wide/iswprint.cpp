#include <iostream>
#include <cwctype>
#include <clocale>
 
int main()
{
    wchar_t c = L'\u2002'; // en-space
    std::setlocale(LC_ALL, "en_US.utf8");
    // g++ must use before -std=c++20, such as 17, 14, 11, not 20 23
#ifdef __clang__
    std::cout << std::boolalpha << std::hex << std::showbase
              << "in Unicode locale,\n"
              << "iswprint('" << c << "') = "
              << (bool)std::iswprint(c) << '\n';
 
    c = L'\u0082'; // break permitted
    std::cout << "iswprint('" << c << "') = "
              << (bool)std::iswprint(c) << '\n';
#endif
}