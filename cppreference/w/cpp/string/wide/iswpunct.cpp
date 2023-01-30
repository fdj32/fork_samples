#include <iostream>
#include <cwctype>
#include <clocale>
 
int main()
{
    wchar_t c = L'\u2051'; // Two asterisks ('⁑')
 
    std::cout << std::hex << std::showbase << std::boolalpha;
    std::cout << "in the default locale, iswpunct(" << (std::wint_t)c << ") = "
              << (bool)std::iswpunct(c) << '\n';
    std::setlocale(LC_ALL, "en_US.utf8");
    std::cout << "in Unicode locale, iswpunct(" << (std::wint_t)c << ") = "
              << (bool)std::iswpunct(c) << '\n';
}